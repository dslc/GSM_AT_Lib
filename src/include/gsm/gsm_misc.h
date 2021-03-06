/**	
 * \file            gsm_misc.h
 * \brief           API for retrieving miscellaneous info from GSM module
 */

#ifndef GSM_HDR_MISC_H
#define GSM_HDR_MISC_H

#ifdef __cplusplus
extern "C" {
#endif

#include "gsm/gsm.h"

/**
 * \ingroup         GSM
 * \defgroup        GSM_BATTERY Battery info API
 * \brief           Miscellaneous API
 * \{
 */

gsmr_t      gsm_battery_info_get(gsm_battery_info_t* curr, const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

/**
 * \}
 */

#ifdef __cplusplus
}
#endif

#endif /* GSM_HDR_MISC_H */
