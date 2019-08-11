/**	
 * \file            gsm_toolkit.h
 * \brief           SIM application toolkit API
 */

#ifndef GSM_HDR_TOOKIT_H
#define GSM_HDR_TOOKIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gsm/gsm.h"

typedef struct {
	char buf[128];
	int len;
} gsm_toolkit_urc_t;

void gsm_toolkit_init(gsm_toolkit_urc_t *urc_buf);
gsmr_t gsm_toolkit_enable(gsm_toolkit_urc_t *urc_buf,
		const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg,
		const uint32_t blocking);
gsmr_t gsm_toolkit_is_enabled(const gsm_api_cmd_evt_fn evt_fn,
		void* const evt_arg, const uint32_t blocking);
gsmr_t gsm_toolkit_raw_command(const char *cmd, const gsm_api_cmd_evt_fn evt_fn,
		void * const evt_arg, const uint32_t blocking);
gsmr_t gsm_toolkit_response(const char *result, const char *text,
		uint8_t use_text, const gsm_api_cmd_evt_fn evt_fn, void * const evt_arg,
		const uint32_t blocking);
gsmr_t gsm_save_active_profile(const gsm_api_cmd_evt_fn evt_fn,
		void* const evt_arg, const uint32_t blocking);
gsmr_t gsm_restricted_sim_access(const uint32_t command, const uint32_t fileId,
		const uint8_t *param, const char *data);

#ifdef __cplusplus
}
#endif

#endif /* GSM_HDR_TOOKIT_H */
