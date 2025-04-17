#include <QApplication>

#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickWindow>

#include <QUrl>

#include "../include/GraphDataUiHandler.h"
#include "../include/DataHandler.h"
#include "../include/TouchstoneParser.h"
#include "../include/ProcessingLogMag.h"
#include "../include/FileUrlCatcher.h"
#include "../include/DataUiManager.h"

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

    DataUiManager manager(hand);
    QObject* root = engine.rootObjects().first();
    GraphDataUiHandler* dataHandler = root->findChild<GraphDataUiHandler*>("graphDataUiHandler");
    if (dataHandler) {
        manager.setDataUiHandler(dataHandler);
        QObject::connect(&boo, &FileUrlCatcher::sendFilePath, &manager, &DataUiManager::filePathChanged);
    } else {
        std::runtime_error("cant find GraphDataUiHandler");
    }

    QObject::connect(&manager, &DataUiManager::sendErrorToQml, root, [root](const QString& errorMessage) {
        QMetaObject::invokeMethod(root, "displayError", Q_ARG(QVariant, errorMessage));
    });

    return app.exec();
}
