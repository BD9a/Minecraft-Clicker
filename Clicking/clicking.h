#ifndef CLICKING_H
#define CLICKING_H

#include <QObject>
#include <QDebug>
#include <windows.h>
#include <QTimer>
#include <ctime>

class Clicking : public QObject
{
    Q_OBJECT
public:
    explicit Clicking(QObject *parent = nullptr);

signals:
    void textChanged(QString);

public slots:
    void setEqBindKey(int value);
    void setMinCpsDelay(int value);
    void setMaxCpsDelay(int value);
    void loopReset();
    void loop();
    void loopStart();
    void leftClick();
    void setWindowName(QString value);



private:
    int bindKey=0x45; // e
    bool enabled = false;
    QString windowName = "Minecraft 1.8.8 (Blazingpack.pl)";
    LPCWSTR windowID = (const wchar_t*) windowName.utf16();
    QTimer *check = new QTimer;

    int minCpsDelay = 10;
    int maxCpsDelay = 15;

};
#endif
