#include "Clicking/clicking.h"


Clicking::Clicking(QObject *parent) : QObject(parent)
{

}

void Clicking::setEqBindKey(int value)
{
    bindKey = value;
}

void Clicking::setMinCpsDelay(int value)
{
    minCpsDelay = value;
}

void Clicking::setMaxCpsDelay(int value)
{
    maxCpsDelay = value;
}

void Clicking::loopReset()
{
    check->start(2);
}

void Clicking::loop()
{
    if(GetAsyncKeyState(0x52) && GetAsyncKeyState(0x01))
    {
        enabled = true;
    }
    if(GetAsyncKeyState(0x01) == 0 || GetAsyncKeyState(bindKey))
    {
        enabled = false;
        //qDebug() << delay;
    }
    if(enabled && GetAsyncKeyState(0x01))
    {
        srand( time( NULL ) );
        leftClick();
        int randomDelay = 1000 / ((rand()%(maxCpsDelay-minCpsDelay))+minCpsDelay);
        Sleep(randomDelay);
    }
}

void Clicking::loopStart()
{
    connect(check, SIGNAL(timeout()), this, SLOT(loop()));
    check->setInterval(0);
    check->start(2);
}

void Clicking::leftClick()
{
    PostMessage(FindWindow(NULL, windowID), WM_LBUTTONDOWN, 0, 0);
    PostMessage(FindWindow(NULL, windowID), WM_LBUTTONUP, 0, 0);
}

void Clicking::setWindowName(QString value){
    connect(this, SIGNAL (textChanged(QString)), this, SLOT(setWindowName(QString)));
    windowName = value;
    windowID = (const wchar_t*) windowName.utf16();
}
