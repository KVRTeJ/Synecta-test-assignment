#include <QApplication>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include <QUrl>

#include "GraphDataUiHandler.h"
#include "DataHandler.h"
#include "TouchstoneParser.h"
#include "ProcessingLogMag.h"
#include "FileUrlCatcher.h"

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("KVRTeJ");
    QCoreApplication::setOrganizationDomain("kvrtej");
#endif
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    qmlRegisterType<GraphDataUiHandler>("App", 1, 0, "GraphDataUiHandler");

    FileUrlCatcher boo;
    engine.rootContext()->setContextProperty("urlCatcher", &boo);
    engine.load(url);

    TouchstoneParser pars;
    ProcessingLogMag proc;
    DataHandler hand;
    hand.setParser(&pars);
    hand.setProcessingUnit(&proc);

    hand.setFilePath("C:\\Users\\dmitriy.filimonov\\Downloads\\samples500k.S1P");

    QVector<double> xData;
    QVector<double> yData;
    hand.getProcessedData(xData, yData);

    QObject *root = engine.rootObjects().first();
    if (!root) {
        qDebug() << "root nlptr";
        return -1;
    }

    GraphDataUiHandler *dataHandler = root->findChild<GraphDataUiHandler*>("graphDataUiHandler");
    if (dataHandler) {
        dataHandler->setData(xData, yData);
    } else {
        qDebug() << "GraphDataUiHandler = nlptr";
    }

    return app.exec();
}
