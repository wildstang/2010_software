#if !defined(_WSAUTONEARKICKNOCRAB_H)
#define _WSAUTONEARKICKNOCRAB_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoNearKickNoCrab : public WsAutoNStepBase
{
    public:
        WsAutoNearKickNoCrab();
        virtual ~WsAutoNearKickNoCrab();
        virtual void initParams(void);
};

#endif
