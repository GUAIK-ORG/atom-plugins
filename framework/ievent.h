#ifndef IEVENT_H
#define IEVENT_H

#include <QString>

#define PLUGIN_EVENT_BASE 0x1000
#define WINDOW_EVENT_BASE 0x2000

typedef struct _SWITCH_WIDGET_EVENT
{
    QString pluginId;
} SWITCH_WIDGET_EVENT;

typedef enum _EVENT_ID
{
    /* 窗口相关事件 */
    SWITCH_WIDGET = WINDOW_EVENT_BASE + 1
} EVENT_ID;

class Event
{
public:
    Event(EVENT_ID id, void *pArg)
    {
        m_id = id;
        m_bNext = true;
        m_pArg = pArg;
    }
    void next() { m_bNext = true; }
    void stop() { m_bNext = false; }
    EVENT_ID id() { return m_id; }
    bool isNext() { return m_bNext; }
    void *arg() { return m_pArg; }

private:
    EVENT_ID m_id;
    bool m_bNext;
    void *m_pArg;
};

class IEventHandler
{
public:
    virtual void onEvent(Event *e) = 0;
};

class EVENT_OBJ
{
public:
    int weight;
    IEventHandler *handler;
    EVENT_OBJ() {}
    EVENT_OBJ(int w, IEventHandler *handler)
    {
        this->weight = w;
        this->handler = handler;
    }
};

class IEventManager
{
public:
    virtual void registerEventHandler(EVENT_ID id, EVENT_OBJ *obj) = 0;
    virtual void unregisterEventHandler(EVENT_ID id, EVENT_OBJ *obj) = 0;
};

#endif