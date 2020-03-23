#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include "oz_common.h"

typedef void (*onUnsolResponseSim)(int response, const void* data);

typedef enum {
  OZ_SIMSERVICE_CARD_STATE_ABSENT,
  OZ_SIMSERVICE_CARD_STATE_PRESENT,
  OZ_SIMSERVICE_CARD_STATE_ERROR,
} oz_simservice_card_state_type;

typedef enum
{
    OZ_SIMSERVICE_STATUS_MODE_UNKNOWN                 = 0,
    OZ_SIMSERVICE_STATUS_MODE_ENABLED_NOT_VERIFIED    = 1,    //PIN Lock Enable
    OZ_SIMSERVICE_STATUS_MODE_ENABLED_VERIFIED        = 2,    //Pin Lock Enable&Pin 1 code verfication
    OZ_SIMSERVICE_STATUS_MODE_DISABLED                = 3,    //Pin Lock disabled
    OZ_SIMSERVICE_STATUS_MODE_BLOCKED                 = 4,    //Pin Block
    OZ_SIMSERVICE_STATUS_MODE_PERMANENTLY_BLOCKED     = 5,
    OZ_SIMSERVICE_STATUS_MODE_NOT_INSTALL             = 6,    //Pin not install=UIM_PIN_STATE_DISABLED_V01
    OZ_SIMSERVICE_STATUS_MODE_INVALID_UIM             = 7,    //Invalid UIM
    OZ_SIMSERVICE_STATUS_MODE_QMI_ERROR               = 0x100,
    OZ_SIMSERVICE_STATUS_MODE_QMI_SUCCESS             = 0x101,
    OZ_SIMSERVICE_STATUS_MODE_MAX
 } oz_simservice_status_mode_type;

oz_Result oz_simservice_init(onUnsolResponseSim callback);

oz_Result oz_simservice_getMccMnc(char *mccMnc);

oz_Result oz_simservice_getGid(char *gid);

oz_Result oz_simservice_getImsi(char *imsi);

oz_Result oz_simservice_getIccid(char *iccid);

oz_Result oz_simservice_getIccid(char *msisdn);

oz_Result oz_simservice_getState(oz_simservice_card_state_type *state);

oz_Result oz_simservice_setActivation(void);

oz_Result oz_simservice_registerEvent(int aEvent);

oz_Result oz_simservice_deregisterEvent(int aEvent);

oz_Result oz_simservice_getStatus(oz_simservice_status_mode_type *status);

oz_Result oz_simservice_getPinBlockTryCnt(int* nPinCnt, int* nPukCnt,  int* result);

oz_Result oz_simservice_setPinEnable(const char* pcmzCHV, bool bPinEnable, int* result);

oz_Result oz_simservice_isVerify(const char* pcmzCHV, int* result);

oz_Result oz_simservice_changePinCode(const char* pcmzOldCHV, const char* pcmzNewCHV, int* result);

oz_Result oz_simservice_unblockPukCode(const char* pcmzUnblockCHV, const char* pcmzNewCHV, int* result);

#ifdef __cplusplus
}
#endif
