#ifndef CLICKING_H
#define CLICKING_H

#include <QObject>
#include <QTimer>
#include <windows.h>
#include <Conf/conf.h>

class Clicking : public QObject
{
    Q_OBJECT
public:
    explicit Clicking(QObject *parent = nullptr);
    Conf *config;

signals:

public slots:
    void loop();
    void loopStart();
    void leftClick();

private:

    bool enabled = false;
    QTimer *check = new QTimer;

};
#endif
