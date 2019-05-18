#ifndef KEYTRANSLATOR_H
#define KEYTRANSLATOR_H

#include <QObject>
#include <ctype.h>
#include <QMap>
#include <QDebug>

class KeyTranslator : public QObject
{
    Q_OBJECT
public:
    explicit KeyTranslator(QObject *parent = nullptr);
    QMap<QString, int> keyCodes;
public slots:
    int getCode(QString key);
    QString getKey(int code);
private:
    void add(QString v0, int v1);

};

#endif // KEYTRANSLATOR_H
