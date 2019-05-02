/**	
 * \file            gsm_nmr.h
 * \brief           Neighborhood Measurement Report (NMR) API
 *
 * This functionality is accessible on SIM800 devices - and possibly other SIMCom devices - via the AT+CELLIST command.
 */

#ifndef GSM_HDR_NMR_H
#define GSM_HDR_NMR_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gsm/gsm.h"

/**
 * \ingroup         GSM
 * \defgroup        GSM_NMR Neighborhood measurement report API
 * \brief           Neighborhood Measurement Report (NMR) API
 * \{
 */

gsmr_t      gsm_nmr_enable(uint16_t refresh_period, const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);
gsmr_t      gsm_nmr_get_list(gsm_nmr_t *nmr, size_t max, const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* GSM_HDR_NMR_H */
