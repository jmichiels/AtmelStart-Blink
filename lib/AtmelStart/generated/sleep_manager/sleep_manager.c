/**
 * \file
 *
 * \brief Sleep manager implementation.
 *
 * Copyright (C) 2015 Atmel Corporation. All rights reserved.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. The name of Atmel may not be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * 4. This software may only be redistributed and used in connection with an
 *    Atmel microcontroller product.
 *
 * THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * EXPRESSLY AND SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * \asf_license_stop
 *
 */

#include <sleep_manager.h>
#include <hal_sleep.h>
#include <utils_assert.h>

/** Event structure used to subscribe to sleep events */
static struct event sleepmgr_event;
/** The list of ready-to-sleep callbacks */
static struct list_descriptor ready_to_sleep_cbs;
/** The list of prepare-to-sleep callbacks */
static struct list_descriptor prepare_to_sleep_cbs;
/** The list of wake up callbacks */
static struct list_descriptor wake_up_cbs;

static void sleepmgr_event_callback(event_id_t id, event_data_t data);

/**
 * \brief Initialize sleep manager
 */
void sleepmgr_init(void)
{
	event_subscribe(&sleepmgr_event, EVENT_PREPARE_TO_SLEEP_ID, sleepmgr_event_callback);
	event_subscribe(&sleepmgr_event, EVENT_IS_READY_TO_SLEEP_ID, sleepmgr_event_callback);
	event_subscribe(&sleepmgr_event, EVENT_WOKEN_UP_ID, sleepmgr_event_callback);
}

/**
 * \brief Register sleep callback
 */
void sleepmgr_register_ready_to_sleep_callback(struct sleepmgr_ready_to_sleep_cb *const cb)
{
	ASSERT(cb);

	list_insert_as_head(&ready_to_sleep_cbs, cb);
}

/**
 * \brief Register wake up callback
 */
void sleepmgr_register_prepare_to_sleep_callback(struct sleepmgr_prepare_to_sleep_cb *const cb)
{
	ASSERT(cb);

	list_insert_as_head(&prepare_to_sleep_cbs, cb);
}

/**
 * \brief Register wake up callback
 */
void sleepmgr_register_wake_up_callback(struct sleepmgr_wake_up_cb *const cb)
{
	ASSERT(cb);

	list_insert_as_head(&wake_up_cbs, cb);
}

/**
 * \brief Go to sleep
 */
void sleepmgr_sleep(const uint8_t mode)
{
	event_post(EVENT_PREPARE_TO_SLEEP_ID, mode);
	sleep(mode);
}

/**
 * \brief Send wake-up notification
 */
void sleepmgr_wakeup(const enum sleepmgr_wakeup_source source)
{
	event_post(EVENT_WOKEN_UP_ID, source);
}

/**
 * \brief Check if device is ready to sleep
 */
bool sleepmgr_is_ready_to_sleep(const uint8_t mode)
{
	struct sleepmgr_ready_to_sleep ready;

	ready.ready = true;
	ready.mode  = mode;

	event_post(EVENT_IS_READY_TO_SLEEP_ID, (event_data_t)&ready);

	return ready.ready;
}

/**
 * \brief "Going to sleep" event callback
 *
 * \param[in] id The event ID to process
 * \param[in] data Not used
 */
static void sleepmgr_event_callback(event_id_t id, event_data_t data)
{
	if (EVENT_IS_READY_TO_SLEEP_ID == id) {
		struct sleepmgr_ready_to_sleep_cb *cur;
		struct sleepmgr_ready_to_sleep *   ret_val = (struct sleepmgr_ready_to_sleep *)data;
		struct sleepmgr_ready_to_sleep     ready;

		for (cur = (struct sleepmgr_ready_to_sleep_cb *)list_get_head(&ready_to_sleep_cbs); cur;
		     cur = (struct sleepmgr_ready_to_sleep_cb *)list_get_next_element(cur)) {
			ready.mode  = ret_val->mode;
			ready.ready = true;
			cur->cb(&ready);
			ret_val->ready &= ready.ready;
		}
	} else if (EVENT_WOKEN_UP_ID == id) {
		struct sleepmgr_wake_up_cb *cur;

		for (cur = (struct sleepmgr_wake_up_cb *)list_get_head(&wake_up_cbs); cur;
		     cur = (struct sleepmgr_wake_up_cb *)list_get_next_element(cur)) {
			cur->cb((const enum sleepmgr_wakeup_source)data);
		}
	} else if (EVENT_PREPARE_TO_SLEEP_ID == id) {
		struct sleepmgr_prepare_to_sleep_cb *cur;

		for (cur = (struct sleepmgr_prepare_to_sleep_cb *)list_get_head(&prepare_to_sleep_cbs); cur;
		     cur = (struct sleepmgr_prepare_to_sleep_cb *)list_get_next_element(cur)) {
			cur->cb(data);
		}
	}
}
