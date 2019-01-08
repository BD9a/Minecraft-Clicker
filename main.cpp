#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <windows.h>
#include <click.h>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qputenv("QT_QUICK_CONTROLS_STYLE", "material");

    if (engine.rootObjects().isEmpty())
        return -1;

    click _click;

    _click.setCps();
    _click.start();

    _click.rsetCps();
    _click.rstart();

    _click.reset();
    _click.rreset();


    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("Click", &_click);

    return app.exec();
}
