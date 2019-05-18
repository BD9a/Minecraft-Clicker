#include "Clicking/clicking.h"


Clicking::Clicking(QObject *parent) : QObject(parent)
{

}

void Clicking::loopReset()
{
    check->start(2);
}

void Clicking::loop()
{
    if(GetAsyncKeyState(config->ctoggleButton) && GetAsyncKeyState(0x01))
    {
        enabled = true;
    }
    if(GetAsyncKeyState(0x01) == 0 || GetAsyncKeyState(config->inventoryKey))
    {
        enabled = false;
        //qDebug() << delay;
    }
    if(enabled && GetAsyncKeyState(0x01))
    {
        srand( time( NULL ) );
        leftClick();
        int randomDelay = 1000 / ((rand()%(config->maxCpsDelay-config->minCpsDelay))+config->minCpsDelay);
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
    PostMessage(FindWindow(NULL, config->windowID), WM_LBUTTONDOWN, 0, 0);
    PostMessage(FindWindow(NULL, config->windowID), WM_LBUTTONUP, 0, 0);
}
