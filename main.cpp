#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <windows.h>
#include <ctime>
#include <Building/building.h>
#include <Clicking/clicking.h>
#include <Keytranslator/keytranslator.h>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qputenv("QT_QUICK_CONTROLS_STYLE", "material");

    if (engine.rootObjects().isEmpty())
        return -1;


    Building building;
    Clicking clicking;
    KeyTranslator ktr;

    building.loopStart();
    clicking.loopStart();

    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("Building", &building);
    ctx->setContextProperty("Clicking", &clicking);

    ctx->setContextProperty("keyTranslator", &ktr);

    return app.exec();
}
