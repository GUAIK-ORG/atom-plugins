
#ifndef __IMQ_H__
#define __IMQ_H___

#include <QByteArray>
#include <QString>

class IMQMessageHandler
{
public:
    virtual void onMessage(QString id, const QByteArray &data) = 0;
};

class IMQMessageManager
{
public:
    virtual void registerMessageHandler(QString topic, IMQMessageHandler *messageHandler) = 0;
    virtual void unregisterMessageHandler(QString topic, IMQMessageHandler *messageHandler) = 0;
    virtual void sendMessage(QString topic, const QByteArray &data) = 0;
};

#endif