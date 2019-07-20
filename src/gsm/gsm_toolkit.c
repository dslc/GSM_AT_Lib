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
gsmr_t gsm_toolkit_enable(gsm_toolkit_urc_t *urc_buf, const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
		const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_TOOLKIT_ENABLE;
	gsm.m.toolkit_urc_buf = urc_buf;

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 2000);
}

#endif
