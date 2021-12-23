#ifndef IPLUGIN_H
#define IPLUGIN_H
#include "icontext.h"
#include <QString>

class IPluginManager
{
public:
    virtual int registerInterfaceObj(IContext *ctx, void *interfaceObj) = 0;
    virtual void *interfaceObj(IContext *ctx, QString id) = 0;
};

class IPlugin
{
public:
    virtual int onLoad(IContext *ctx) = 0;
    virtual int onInit() = 0;
    virtual void onUnload() = 0;
};

#endif // IPLUGIN_H
