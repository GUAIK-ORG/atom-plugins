#ifndef IMESSAGE_H
#define IMESSAGE_H
#include <QString>

class IMessageHandler
{
public:
    virtual void onMessage(QString id, void *pArg) = 0;
};

class IMessageManager
{
public:
    virtual void registerMessageHandler(QString id, IMessageHandler *messageHandler) = 0;
    virtual void unregisterMessageHandler(QString id, IMessageHandler *messageHandler) = 0;
    virtual void sendMessage(QString id, void *pArg) = 0;
};

#endif // IMESSAGEHAND
