#ifndef CONF_H
#define CONF_H

#include <QObject>
#include <QDebug>
#include <windows.h>
#include <QSettings>
#include <QDir>

class Conf : public QObject
{
    Q_OBJECT
public:
    explicit Conf(QObject *parent = nullptr);

    Q_PROPERTY(int input1 READ input1 WRITE setcToggleButton NOTIFY textChanged1)
    Q_PROPERTY(int input2 READ input2 WRITE setbToggleButton NOTIFY textChanged2)
    Q_PROPERTY(int input3 READ input3 WRITE setEqBindKey NOTIFY textChanged3)
    Q_PROPERTY(int input4 READ input4 WRITE setMinCpsDelay NOTIFY textChanged4)
    Q_PROPERTY(int input5 READ input5 WRITE setMaxCpsDelay NOTIFY textChanged5)
    Q_PROPERTY(int input6 READ input6 WRITE setDelay NOTIFY textChanged6)
    Q_PROPERTY(QString input7 READ input7 WRITE setWindowName NOTIFY textChanged7)

    int ctoggleButton = 82;
    int btoggleButton = 82;
    int inventoryKey = 69;
    int minCpsDelay = 10;
    int maxCpsDelay = 15;
    int delay = 100;
    QString windowName = "Minecraft 1.8.8 (Blazingpack.pl)";
    LPCWSTR windowID = (const wchar_t*) windowName.utf16();

    int input1(){
        return ctoggleButton;
    }
    int input2(){
        return btoggleButton;
    }
    int input3(){
        return inventoryKey;
    }
    int input4(){
        return minCpsDelay;
    }
    int input5(){
        return maxCpsDelay;
    }
    int input6(){
        return delay;
    }
    QString input7(){
        return windowName;
    }
signals:

    void textChanged1(int);
    void textChanged2(int);
    void textChanged3(int);
    void textChanged4(int);
    void textChanged5(int);
    void textChanged6(int);
    void textChanged7(QString);

public slots:

    void setcToggleButton(int value);
    void setbToggleButton(int value);
    void setEqBindKey(int value);
    void setMinCpsDelay(int value);
    void setMaxCpsDelay(int value);
    void setDelay(int value);
    void setWindowName(QString value);

    void save();
    void load();
    void create();
private:
    QSettings* settings;

};

#endif // CONF_H
