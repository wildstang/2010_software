#if !defined(_WSAUTOFARLEFTKICK3_H)
#define _WSAUTOFARLEFTKICK3_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoFarLeftKick3 : public WsAutoNStepBase
{
    public:
        WsAutoFarLeftKick3();
        virtual ~WsAutoFarLeftKick3();
        virtual void initParams(void);
};

#endif
