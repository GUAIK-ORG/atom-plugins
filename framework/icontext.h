#ifndef ICONTEXT_H
#define ICONTEXT_H

#include <QString>

typedef enum _QUERY_TYPE
{
    PLUGIN_MANAGER = 0x1000, // 插件管理器对象
    WINDOW_MANAGER,          // 窗口管理器对象
    MESSAGE_MANAGER,         // 消息管理器对象
    MQ_MANAGER,              // 消息队列管理器对象
    LOG_MANAGER,             // 日志管理器对象
    STORAGE_MANAGER,         // 存储管理器对象
    EVENT_MANAGER,           // 事件管理器对象
} QUERY_TYPE;

class IContext
{
public:
    virtual int query(QUERY_TYPE type, void **ptr) = 0;
    virtual const QString &token() = 0;
    virtual const QString &id() = 0;
};

#endif // ICONTEXT_H
