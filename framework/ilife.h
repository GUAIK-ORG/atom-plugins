#ifndef ILIFE_H
#define ILIFE_H
#include "icontext.h"

class ILife
{
public:
    virtual void onBeforeLoadPlugin(IContext *ctx) = 0;
    virtual void onAfterLoadPlugin(IContext *ctx) = 0;

    virtual void onBeforeInitPlugin(IContext *ctx) = 0;
    virtual void onAfterInitPlugin(IContext *ctx) = 0;

    virtual void onBeforeShow(IContext *ctx) = 0;
    virtual void onAfterShow(IContext *ctx) = 0;

    virtual void onBeforeFree(IContext *ctx) = 0;
    virtual void onAfterFree() = 0;
};

#endif // ILIFE_H
