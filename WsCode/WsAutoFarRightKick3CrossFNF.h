#if !defined(_WSAUTOFARRIGHTKICK3CROSSFNF_H)
#define _WSAUTOFARRIGHTKICK3CROSSFNF_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoFarRightKick3CrossFNF : public WsAutoNStepBase
{
    public:
        WsAutoFarRightKick3CrossFNF();
        virtual ~WsAutoFarRightKick3CrossFNF();
        virtual void initParams(void);
    private:
        WsPid* ap_rollOffBumpPid;
        WsPid* ap_climbBumpPid;
};

#endif
