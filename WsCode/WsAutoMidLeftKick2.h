#if !defined(_WSAUTOMIDLEFTKICK2_H)
#define _WSAUTOMIDLEFTKICK2_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoMidLeftKick2 : public WsAutoNStepBase
{
    public:
        WsAutoMidLeftKick2();
        virtual ~WsAutoMidLeftKick2();
        virtual void initParams(void);
};

#endif
