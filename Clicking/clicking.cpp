#include "Clicking/clicking.h"

Clicking::Clicking(QObject *parent) : QObject(parent){
    connect(check, SIGNAL(timeout()), this, SLOT(loop()));
    check->setTimerType(Qt::PreciseTimer);
}

void Clicking::loop(){
    int randomDelay;
    randomDelay = 1000 / ((rand()%(config->maxCpsDelay-config->minCpsDelay))+config->minCpsDelay);

    if(GetAsyncKeyState(config->ctoggleButton) && GetAsyncKeyState(0x01)){
        enabled = true;
    }
    if(GetAsyncKeyState(0x01) == 0 || GetAsyncKeyState(config->inventoryKey)){
        enabled = false;
    }
    if(enabled && GetAsyncKeyState(0x01)){
        leftClick();
        Sleep(randomDelay);
    }
}

void Clicking::loopStart(){
    check->start(2);
}

void Clicking::leftClick(){
    PostMessage(FindWindow(NULL, config->windowID), WM_LBUTTONDOWN, 0, 0);
    PostMessage(FindWindow(NULL, config->windowID), WM_LBUTTONUP, 0, 0);
}
