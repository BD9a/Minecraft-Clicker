#include "click.h"


click::click(QObject *parent) : QObject(parent)
{

}

void click::cursor(bool value)
{
    cursorActive = value;
    qDebug() << cursorActive;
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
        CURSORINFO ci = {sizeof(CURSORINFO)};

        if (GetCursorInfo(&ci))
        {
            if (ci.flags == 0)
                qDebug()<< "cursor is hidden"; // cursor is hidden
            else if (ci.flags == 1)
                qDebug()<< "cursor is visible"; // cursor is visible
            else if (ci.flags == 2)
                qDebug()<< "cursor is suppressed"; // cursor is suppressed
            else
                qDebug()<< "this shouldn't happen!"; // this shouldn't happen!
        }
        else
        {
            qDebug()<< "error"; // GetCursorInfo function failed
        }

        if(GetAsyncKeyState(0x52) && GetAsyncKeyState(0x01))
        {
            rLMB = true;
        }
        if(GetAsyncKeyState(0x01) == 0)
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
        if(GetAsyncKeyState(0x02) == 0)
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
        rcheck->setInterval(0);
        rcheck->start(rdelay);
    }

    void click::RightClick()
    {
        PostMessage(FindWindow(NULL, windowName), WM_RBUTTONDOWN, 0, 0);
        PostMessage(FindWindow(NULL, windowName), WM_RBUTTONUP, 0, 0);
    }

