#include "click.h"


click::click(QObject *parent) : QObject(parent)
{

}

void click::bridge(bool value)
{
    bridgeActive = value;
    qDebug() << bridgeActive;
}

//LMB

    void click::settingCps(int value)
    {
        delay = 1000 / value;
        //qDebug() << delay << "cps";
    }


    void click::setCps()
    {
        connect(this, SIGNAL (cpsChanged(int)), this, SLOT(settingCps(int)));
        connect(this, SIGNAL (textChanged(QString)), this, SLOT(target(QString)));
    }


    void click::reset()
    {
        check->start(delay);
    }

    void click::loop()
    {

        if(GetAsyncKeyState(0x52) && GetAsyncKeyState(0x01))
        {
            rLMB = true;
        }
        if(GetAsyncKeyState(0x01) == 0 || GetAsyncKeyState(eqBindKey))
        {
            rLMB = false;
            //qDebug() << delay;
        }
        if(rLMB && GetAsyncKeyState(0x01))
        {
            LeftClick();
        }
    }

    void click::start()
    {
        connect(check, SIGNAL(timeout()), this, SLOT(loop()));
        check->setInterval(0);
        check->start(delay);
    }

    void click::LeftClick()
    {
        PostMessage(FindWindow(NULL, windowName), WM_LBUTTONDOWN, 0, 0);
        PostMessage(FindWindow(NULL, windowName), WM_LBUTTONUP, 0, 0);
    }

//RMB

    void click::rsettingCps(int value)
    {
        rdelay = 1000 / value;
        //qDebug() << rdelay << "cps";
    }


    void click::rsetCps()
    {
        connect(this, SIGNAL (rcpsChanged(int)), this, SLOT(rsettingCps(int)));
    }


    void click::rreset()
    {
        rcheck->start(rdelay);
    }

    void click::rloop()
    {
        if(GetAsyncKeyState(0x52) && GetAsyncKeyState(0x02))
        {
            rRMB = true;
        }
        if(GetAsyncKeyState(0x02) == 0 || GetAsyncKeyState(eqBindKey))
        {
            rRMB = false;
            //qDebug() << rdelay;
           // qDebug() << "rdelay";
        }
        if(rRMB && GetAsyncKeyState(0x02))
        {
            //qDebug() << "Right";
            RightClick();
        }
    }

    void click::rstart()
    {
        connect(rcheck, SIGNAL(timeout()), this, SLOT(rloop()));
        connect(rcheck, SIGNAL(timeout()), this, SLOT(bridging()));
        rcheck->setInterval(0);
        rcheck->start(rdelay);
    }

    void click::RightClick()
    {
        PostMessage(FindWindow(NULL, windowName), WM_RBUTTONDOWN, 0, 0);
        PostMessage(FindWindow(NULL, windowName), WM_RBUTTONUP, 0, 0);
    }

    void click::bridging()
    {

        HWND current = GetForegroundWindow();
        HWND filled = FindWindow(NULL, windowName);

        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.wScan = 0; // hardware scan code for key
        ip.ki.time = 0;
        ip.ki.dwExtraInfo = 0;

        if(GetAsyncKeyState(bridgeBindKey) && GetAsyncKeyState(0x12) && current == filled) // and marked
        {
                pauseBridge();
            //lshift down
            ip.ki.wVk = 0xA0;
            ip.ki.dwFlags = 0;
            SendInput(1, &ip, sizeof(INPUT));
                pauseBridge();
            Sleep(50);


            //s down
            ip.ki.wVk = 0x53;
            ip.ki.dwFlags = 0;
            SendInput(1, &ip, sizeof(INPUT));

                pauseBridge();
            //sleep
            Sleep(140);

            PostMessage(FindWindow(NULL, windowName), WM_RBUTTONDOWN, 0, 0);
            PostMessage(FindWindow(NULL, windowName), WM_RBUTTONUP, 0, 0);


            Sleep(30);

                pauseBridge();

            ip.ki.wVk = 0xA0; //lshift
            ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
            SendInput(1, &ip, sizeof(INPUT));

                pauseBridge();

            Sleep(200);
        }
    }

    void click::pauseBridge()
    {
        if(GetAsyncKeyState(bridgeBindKey) == 0) // or unmarked
        {
            INPUT ip;
            ip.type = INPUT_KEYBOARD;
            ip.ki.wScan = 0; // hardware scan code for key
            ip.ki.time = 0;
            ip.ki.dwExtraInfo = 0;

            ip.ki.wVk = 0xA0; //lshift
            ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
            SendInput(1, &ip, sizeof(INPUT));

            ip.ki.wVk = 0x53; //s
            SendInput(1, &ip, sizeof(INPUT));
        }
    }

    void click::setEqBindKey(int value)
    {
        eqBindKey = value;
    }

    void click::setBridgeBindKey(int value)
    {
        bridgeBindKey = value;
    }

//TODO Better  QML
//TODO Clicks Randomizer
