#ifndef CONF_H
#define CONF_H

#include <QObject>
#include <windows.h>
#include <QSettings>
#include <QDir>

class Conf : public QObject
{
    Q_OBJECT
public:
    explicit Conf(QObject *parent = nullptr);

    Q_PROPERTY(int clickingButton READ ctoggleButtonFunc WRITE setcToggleButton)
    Q_PROPERTY(int buildingButton READ btoggleButtonFunc WRITE setbToggleButton)
    Q_PROPERTY(int inventoryButton READ inventoryKeyFunc WRITE setEqBindKey)
    Q_PROPERTY(int minCps READ minCpsDelayFunc WRITE setMinCpsDelay)
    Q_PROPERTY(int maxCps READ maxCpsDelayFunc WRITE setMaxCpsDelay)
    Q_PROPERTY(int delay READ delayFunc WRITE setDelay)
    Q_PROPERTY(QStringList nazwy READ bumpNames)

    int ctoggleButton = 82;
    int btoggleButton = 82;
    int inventoryKey = 69;
    int minCpsDelay = 10;
    int maxCpsDelay = 15;
    int delay = 100;

    int ctoggleButtonFunc(){
        return ctoggleButton;
    }
    int btoggleButtonFunc(){
        return btoggleButton;
    }
    int inventoryKeyFunc(){
        return inventoryKey;
    }
    int minCpsDelayFunc(){
        return minCpsDelay;
    }
    int maxCpsDelayFunc(){
        return maxCpsDelay;
    }
    int delayFunc(){
        return delay;
    }

    QString windowName = "Minecraft 1.8.8 (Blazingpack.pl)";
    LPCWSTR windowID = (const wchar_t*) windowName.utf16();

signals:

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

    QStringList bumpNames();
private:
    QSettings* settings;
    bool startup = true;

};

#endif // CONF_H
