#if !defined(_WSAUTONEARRIGHTKICK1_H)
#define _WSAUTONEARRIGHTKICK1_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoNearRightKick1 : public WsAutoNStepBase
{
    public:
        WsAutoNearRightKick1();
        virtual ~WsAutoNearRightKick1();
        virtual void initParams(void);
};

#endif
