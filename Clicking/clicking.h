#ifndef CLICKING_H
#define CLICKING_H

#include <QObject>
#include <QDebug>
#include <windows.h>
#include <QTimer>
#include <ctime>
#include <Conf/conf.h>

class Clicking : public QObject
{
    Q_OBJECT
public:
    explicit Clicking(QObject *parent = nullptr);
    Conf *config;

signals:

public slots:
    void loopReset();
    void loop();
    void loopStart();
    void leftClick();

private:

    bool enabled = false;
    QTimer *check = new QTimer;

};
#endif
