/**	
 * \file            gsm_nmr.c
 * \brief           Neighborhood measurement reports API functions
 */

#include "gsm/gsm_private.h"
#include "gsm/gsm_nmr.h"
#include "gsm/gsm_mem.h"

/**
 * \brief           Enable Neighborhood Measurement Reports
 * \param[in]       refresh_period: Period for refreshing cell list
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref gsmOK on success, member of \ref gsmr_t enumeration otherwise
 */
gsmr_t gsm_nmr_enable(uint16_t refresh_period, const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
		const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_NMR_ENABLE;
	GSM_MSG_VAR_REF(msg).msg.nmr_enable.refresh_period = refresh_period;

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 2000);
}

/**
 * \brief           Retrieve list of neighborhood measurement reports (NMRs)
 * \param[out]      nmr: Pointer to NMR array
 * \param[in]       max: Length of NMR array
 * \param[in]       evt_fn: Callback function called when command has finished. Set to `NULL` when not used
 * \param[in]       evt_arg: Custom argument for event callback function
 * \param[in]       blocking: Status whether command should be blocking or not
 * \return          \ref gsmOK on success, member of \ref gsmr_t enumeration otherwise
 */
gsmr_t gsm_nmr_get_list(gsm_nmr_t *nmr, size_t max,
		const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking) {
	GSM_MSG_VAR_DEFINE(msg);

	GSM_MSG_VAR_ALLOC(msg);
	GSM_MSG_VAR_SET_EVT(msg);
	GSM_MSG_VAR_REF(msg).cmd_def = GSM_CMD_NMR_GET_LIST;

	GSM_MSG_VAR_REF(msg).msg.nmr_list.curr = nmr;
	GSM_MSG_VAR_REF(msg).msg.nmr_list.etr = max;
	GSM_MSG_VAR_REF(msg).msg.nmr_list.ei = 0;

	return gsmi_send_msg_to_producer_mbox(&GSM_MSG_VAR_REF(msg),
			gsmi_initiate_cmd, 4000);
}
