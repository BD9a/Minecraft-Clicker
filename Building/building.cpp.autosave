#include "Building/building.h"


Building::Building(QObject *parent) : QObject(parent)
{
}

void Building::setEqBindKey(int value)
{
    bindKey = value;
}

void Building::setDelay(int value)
{
    delay = 1000 / value;
}

void Building::loopReset()
{
    check->start(delay);
}

void Building::loop()
{
    if(GetAsyncKeyState(0x52) && GetAsyncKeyState(0x02))
    {
        enabled = true;
    }
    if(GetAsyncKeyState(0x02) == 0 || GetAsyncKeyState(bindKey))
    {
        enabled = false;
    }
    if(enabled && GetAsyncKeyState(0x02))
    {
        rightClick();
    }
}

void Building::loopStart()
{
    connect(check, SIGNAL(timeout()), this, SLOT(loop()));
    check->setInterval(0);
    check->start(delay);
}

void Building::rightClick()
{
    PostMessage(FindWindow(NULL, windowID), WM_RBUTTONDOWN, NULL, NULL);
    PostMessage(FindWindow(NULL, windowID), WM_RBUTTONUP, NULL, NULL);
}

void Building::setWindowName(QString value){
    connect(this, SIGNAL (textChanged(QString)), this, SLOT(setWindowName(QString)));
    windowName = value;
    windowID = (const wchar_t*) windowName.utf16();
}
