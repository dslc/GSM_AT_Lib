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

gsmr_t      gsm_toolkit_enable(const gsm_api_cmd_evt_fn evt_fn, void* const evt_arg, const uint32_t blocking);

#ifdef __cplusplus
}
#endif

#endif /* GSM_HDR_TOOKIT_H */
