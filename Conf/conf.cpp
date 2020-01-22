#include "conf.h"

Conf::Conf(QObject *parent) : QObject(parent){
}


QStringList Conf::bumpNames(){

    QStringList processes;
    if(!startup){
        for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)){
            if (!IsWindowVisible(hwnd)) continue;

            int length = GetWindowTextLength(hwnd);
            if (length == 0) continue;

            char* title = new char[length+1];
            GetWindowTextA(hwnd, title, length+1);

            if(strcmp(title, "Program Manager") == 0 || strcmp(title, "Minecraft Clicker") == 0 || strcmp(title, "Microsoft Text Input Application") == 0)
                continue;

            processes << title;

        }
    }
    else{
        startup = false;
        processes << windowName;
    }

    return processes;
}

void Conf::save(){
    QSettings settings("clickerconfig",QSettings::IniFormat);

    settings.setValue("minCpsDelay",minCpsDelay);
    settings.setValue("maxCpsDelay",maxCpsDelay);
    settings.setValue("windowName",windowName);
    settings.setValue("delay",delay);

    settings.sync();
}

void Conf::load(){
    QSettings settings("clickerconfig",QSettings::IniFormat);

    minCpsDelay = settings.value("minCpsDelay").toInt();
    maxCpsDelay = settings.value("maxCpsDelay").toInt();
    windowName = settings.value("windowName").toString();
    delay = settings.value("delay").toInt();
    windowID = (const wchar_t*) windowName.utf16();
}

void Conf::create(){
    if(QFile("clickerconfig").exists()){
        load();
    }
    else{

        QSettings settings("clickerconfig",QSettings::IniFormat);

        settings.setValue("minCpsDelay",minCpsDelay);
        settings.setValue("maxCpsDelay",maxCpsDelay);
        settings.setValue("delay",delay);

        settings.sync();
    }
}


void Conf::setbToggleButton(int value){
    btoggleButton = value;
}

void Conf::setcToggleButton(int value){
    ctoggleButton = value;
}

void Conf::setEqBindKey(int value){
    inventoryKey = value;
}

void Conf::setMinCpsDelay(int value){
    minCpsDelay = value;
}

void Conf::setMaxCpsDelay(int value){
    maxCpsDelay = value;
}

void Conf::setDelay(int value){
    delay = value;
}

void Conf::setWindowName(QString value){
    windowName = value;
    windowID = (const wchar_t*) windowName.utf16();
}
