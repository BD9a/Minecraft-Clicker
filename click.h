#ifndef CLICK_H
#define CLICK_H

#include <QObject>
#include <QDebug>
#include <windows.h>
#include <QTimer>

class click : public QObject
{
    Q_OBJECT
public:
    explicit click(QObject *parent = nullptr);



//LMB
    int delay = 100;
    bool rLMB = false;
    QTimer *check = new QTimer;

//RMB
    int rdelay = 10;
    bool rRMB = false;
    QTimer *rcheck = new QTimer;
signals:
//LMB

        void cpsChanged(int);
//RMB
        void rcpsChanged(int);
        void textChanged(QString);
public slots:
//LMB

        void target(QString value){
            window = value;
            qDebug() << "value" << value;
            qDebug() << "window" << window;
        }
        void bridge(bool value);

        void settingCps(int value);
        void setCps();
        void reset();
        void loop();
        void start();
        void LeftClick();
//RMB
        void rsettingCps(int value);
        void rsetCps();
        void rreset();
        void rloop();
        void rstart();
        void RightClick();
        void bridging();
        void pauseBridge();


        void setEqBindKey(int value);
        void setBridgeBindKey(int value);
private:

        int eqBindKey=0x45; //  E - Inventory key
        int bridgeBindKey=0x5A; // Z - Bridge Key
        bool bridgeActive = false;
        QString window = "Minecraft 1.8.8 (Blazingpack.pl)";
        LPCWSTR windowName = (const wchar_t*) window.utf16();

};

#endif // CLICK_H