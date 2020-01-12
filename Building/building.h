#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>
#include <windows.h>
#include <QTimer>
#include <Conf/conf.h>


class Building : public QObject
{
    Q_OBJECT
public:
    explicit Building(QObject *parent = nullptr);
    Conf *config;

signals:

public slots:
    void loop();
    void loopStart();
    void rightClick();

private:
    bool enabled = false;
    QTimer *check = new QTimer;

};
#endif
