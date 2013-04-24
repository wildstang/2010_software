#if !defined(_WSAUTOFARRIGHTKICK3CLEAR_H)
#define _WSAUTOFARRIGHTKICK3CLEAR_H

#include <stdio.h>
#include "WsAutoNStepBase.h"

class WsAutoFarRightKick3Clear : public WsAutoNStepBase
{
    public:
        WsAutoFarRightKick3Clear();
        virtual ~WsAutoFarRightKick3Clear();
        virtual void initParams(void);
};

#endif
