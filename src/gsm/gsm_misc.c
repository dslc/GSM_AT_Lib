/**	
 * \file            gsm_misc.c
 * \brief           Miscellaneous API functions
 */

#include "gsm/gsm_private.h"
#include "gsm/gsm_misc.h"

/**
 * \brief           Get battery information
 * \param[out]      curr: Pointer to output variable to save battery information
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref gsmOK on success, member of \ref gsmr_t enumeration otherwise
 */
gsmr_t gsm_battery_info_get(gsm_battery_info_t* curr,
		const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
		const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_BATTERY_INFO;
	GSM_MSG_VAR_REF(msg).msg.battery_info.curr = curr;

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 2000);
}
