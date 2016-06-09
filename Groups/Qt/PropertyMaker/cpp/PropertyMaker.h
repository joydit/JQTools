﻿#ifndef __PropertyMaker_h__
#define __PropertyMaker_h__

// C++ lib import
#include <functional>

// Qt lib import
#include <QObject>
#include <QMap>

#define PROPERTYMAKER_INITIALIZA                                                            \
{                                                                                           \
    qmlRegisterType<PropertyMaker::Manage>("PropertyMaker", 1, 0, "PropertyMakerManage");   \
}

namespace PropertyMaker
{

class Manage: public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(Manage)

public:
    Manage();

    ~Manage() = default;

public slots:
    QString make(const QString &source, const bool &withSlot, const bool &withInline);

    QString clipboardText();

    void setClipboardText(const QString &string);

private:
    QMap< QString, std::function< QString( const QString &type, const QString &name, const QString &value, const QString &notifyValue, const bool &withSlot, const bool &withInline ) > > propertyMaker_;
};

}

#endif//__PropertyMaker_h__
