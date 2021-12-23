#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "icontext.h"
#include "imessage.h"
#include "imq.h"

class MainWidget : public QWidget, public IMessageHandler, public IMQMessageHandler
{
    Q_OBJECT
public:
    explicit MainWidget(IContext* ctx, QWidget *parent = nullptr);

private:
    IContext* m_ctx;
    bool m_showStatusbar = true;

protected:
    void onMessage(QString id, void *pArg) override;
    void onMessage(QString id, const QByteArray &data) override;

signals:

public slots:
};

#endif // MAINWIDGET_H
