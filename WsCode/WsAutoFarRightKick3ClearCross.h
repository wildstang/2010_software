#if !defined(_WSAUTOFARRIGHTKICK3CLEARCROSS_H)
#define _WSAUTOFARRIGHTKICK3CLEARCROSS_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsPid;

class WsAutoFarRightKick3ClearCross : public WsAutoNStepBase
{
    public:
        WsAutoFarRightKick3ClearCross();
        virtual ~WsAutoFarRightKick3ClearCross();
        virtual void initParams(void);
    private:
        WsPid* ap_rollOffBumpPid;
        WsPid* ap_climbBumpPid;
};

#endif
