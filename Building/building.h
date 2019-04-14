#ifndef BUILDING_H
#define BUILDING_H

#include <QObject>
#include <QDebug>
#include <windows.h>
#include <QTimer>

class Building : public QObject
{
    Q_OBJECT
public:
    explicit Building(QObject *parent = nullptr);

signals:
    void textChanged(QString);

public slots:
    void setEqBindKey(int value);
    void setDelay(int value);
    void loopReset();
    void loop();
    void loopStart();
    void rightClick();
    void setWindowName(QString value);
    void setToggleButton(int value);

private:
    bool enabled = false;
    int toggleButton=0x52; // r
    int inventoryKey=0x45; // e
    QString windowName = "Minecraft 1.8.8 (Blazingpack.pl)";
    LPCWSTR windowID = (const wchar_t*) windowName.utf16();
    int delay = 10;
    QTimer *check = new QTimer;

};
#endif
