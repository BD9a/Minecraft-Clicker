#include "conf.h"

Conf::Conf(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL (textChanged1(int)), this, SLOT(setcToggleButton(int)));
    connect(this, SIGNAL (textChanged2(int)), this, SLOT(setbToggleButton(int)));
    connect(this, SIGNAL (textChanged3(int)), this, SLOT(setEqBindKey(int)));
    connect(this, SIGNAL (textChanged4(int)), this, SLOT(setMinCpsDelay(int)));
    connect(this, SIGNAL (textChanged5(int)), this, SLOT(setMaxCpsDelay(int)));
    connect(this, SIGNAL (textChanged6(int)), this, SLOT(setDelay(int)));
    connect(this, SIGNAL (textChanged7(QString)), this, SLOT(setWindowName(QString)));

}

void Conf::save()
{
    QSettings settings("clickerconfig",QSettings::IniFormat);
    //settings.setValue("ctoggleButton",ctoggleButton);
    //settings.setValue("btoggleButton",btoggleButton);
    //settings.setValue("inventoryKey",inventoryKey);
    settings.setValue("minCpsDelay",minCpsDelay);
    settings.setValue("maxCpsDelay",maxCpsDelay);
    settings.setValue("delay",delay);
    settings.setValue("windowName",windowName);
    //settings.setValue("windowID",windowID);

    settings.sync();
}

void Conf::load()
{
    QSettings settings("clickerconfig",QSettings::IniFormat);
    //ctoggleButton = settings.value("ctoggleButton").toInt();
    //btoggleButton = settings.value("btoggleButton").toInt();
    //inventoryKey = settings.value("inventoryKey").toInt();
    minCpsDelay = settings.value("minCpsDelay").toInt();
    maxCpsDelay = settings.value("maxCpsDelay").toInt();
    delay = settings.value("delay").toInt();
    windowName = settings.value("windowName").toString();
    windowID = (const wchar_t*) windowName.utf16();

}

void Conf::create()
{
    if(QFile("clickerconfig").exists()){
        load();
    }
    else{

        QSettings settings("clickerconfig",QSettings::IniFormat);
        //settings.setValue("ctoggleButton",ctoggleButton);
        //settings.setValue("btoggleButton",btoggleButton);
        //settings.setValue("inventoryKey",inventoryKey);
        settings.setValue("minCpsDelay",minCpsDelay);
        settings.setValue("maxCpsDelay",maxCpsDelay);
        settings.setValue("delay",delay);
        settings.setValue("windowName",windowName);
        //settings.setValue("windowID",windowID);

        settings.sync();
    }
}


void Conf::setbToggleButton(int value)
{
    btoggleButton = value;
}

void Conf::setcToggleButton(int value)
{
    ctoggleButton = value;
}

void Conf::setEqBindKey(int value)
{
    inventoryKey = value;
}

void Conf::setMinCpsDelay(int value)
{
    minCpsDelay = value;
}

void Conf::setMaxCpsDelay(int value)
{
    maxCpsDelay = value;
}

void Conf::setDelay(int value)
{
    delay = value;
}

void Conf::setWindowName(QString value)
{
    windowName = value;
    windowID = (const wchar_t*) windowName.utf16();
    qDebug() << windowID;
}
