#if !defined(_WSAUTOFARRIGHTKICK3CROSSFFF_H)
#define _WSAUTOFARRIGHTKICK3CROSSFFF_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoFarRightKick3CrossFFN : public WsAutoNStepBase
{
    public:
        WsAutoFarRightKick3CrossFFN();
        virtual ~WsAutoFarRightKick3CrossFFN();
        virtual void initParams(void);
    private:
        WsPid* ap_rollOffBumpPid;
        WsPid* ap_climbBumpPid;
};

#endif
