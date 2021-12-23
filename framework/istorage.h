#ifndef __ISTORAGE_H__
#define __ISTORAGE_H__

#include <QString>
#include <QMap>

typedef QMap<QString, QString> STORAGE_DATA;

class IStorageManager
{
public:
    // 同步
    virtual QString get(const QString &key) = 0;
    virtual bool put(const QString &key, const QString &value) = 0;
    virtual bool del(const QString &key) = 0;
    // 异步
    virtual bool aPut(const QString &key, const QString &value) = 0;
    virtual bool aDel(const QString &key) = 0;
    virtual QMap<QString, QString> data() = 0;
};

#endif