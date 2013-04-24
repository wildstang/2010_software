#if !defined(_WSAUTOFARRIGHTKICK3LOW_H)
#define _WSAUTOFARRIGHTKICK3LOW_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoFarRightKick3Low : public WsAutoNStepBase
{
    public:
        WsAutoFarRightKick3Low();
        virtual ~WsAutoFarRightKick3Low();
        virtual void initParams(void);
};

#endif
