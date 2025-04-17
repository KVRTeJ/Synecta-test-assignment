#include <QDebug>

#include "DataUiManager.h"

void DataUiManager::filePathChanged(const QString filePath) {
    qDebug() << "filePathChanged starded";
    if(filePath.isEmpty()) {
        m_dataUiHandler->setData({}, {});
    }

    qDebug() << filePath;
    QVector<double> xAxis, yAxis;

    m_dataHandler.setFilePath(filePath);
    m_dataHandler.getProcessedData(xAxis, yAxis);

    if(m_dataUiHandler)
        m_dataUiHandler->setData(xAxis, yAxis);
}

void DataUiManager::handleFileOpenError(const QString& errorMessage) {
    emit sendErrorToQml(errorMessage);
}

void DataUiManager::handleFileFormatError(const QString& errorMessage) {
    emit sendErrorToQml(errorMessage);
}
