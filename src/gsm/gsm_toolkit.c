/**	
 * \file            gsm_nmr.c
 * \brief           Neighborhood measurement reports API functions
 */

#include "gsm/gsm_private.h"
#include "gsm/gsm_toolkit.h"
#include "gsm/gsm_mem.h"

#if GSM_CFG_TOOLKIT || __DOXYGEN__

/**
 * \brief           Enable URCs (unsolicted response codes) for SIM application toolkit
 * \param[in]		urc_buf: Buffer for storing unsolicited response codes
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref gsmOK on success, member of \ref gsmr_t enumeration otherwise
 */
gsmr_t gsm_toolkit_enable(gsm_toolkit_urc_t *urc_buf,
		const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
		const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_TOOLKIT_ENABLE;
	gsm.m.toolkit_urc_buf = urc_buf;

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 2000);
}

/**
 * \brief           Send a raw command to the GSM module.
 *
 * This is primarily intended for use with the SIM application toolkit, but could be used for other purposes.
 *
 * \param[in]		cmd: The raw command to send
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref gsmOK on success, member of \ref gsmr_t enumeration otherwise
 */
gsmr_t gsm_toolkit_raw_command(const char *cmd, const gsm_api_cmd_evt_fn evt_fn,
		void * const evt_arg, const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_TOOLKIT_RAW_CMD;
	strcpy(GSM_MSG_VAR_REF(msg).msg.toolkit_cmd.cmd, cmd);

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 2000);
}

/**
 * \brief           Send a terminal response.
 *
 * \param[in]		result: Hex string - should be either '00', '10' or '11'.
 * \param[in]		text: Hex string
 * \param[in]		use_text: 0 or 1 to indicate if text parameter should be included
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref gsmOK on success, member of \ref gsmr_t enumeration otherwise
 */
gsmr_t gsm_toolkit_response(const char *result, const char *text,
		uint8_t use_text, const gsm_api_cmd_evt_fn evt_fn, void * const evt_arg,
		const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_TOOLKIT_RESPONSE;
	strcpy(GSM_MSG_VAR_REF(msg).msg.toolkit_response.result, result);
	GSM_MSG_VAR_REF(msg).msg.toolkit_response.use_text = use_text;
	if (use_text) {
		strcpy(GSM_MSG_VAR_REF(msg).msg.toolkit_response.text, text);
	}

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 2000);
}

#endif
