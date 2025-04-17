#include "DataUiManager.h"

void DataUiManager::setDataUiHandler(IDataUiHandler* handler) {
    m_dataUiHandler = handler;
    if (m_dataUiHandler) {
        connect(m_dataHandler.getParser(), &IParser::fileOpenError, this, &DataUiManager::handleFileOpenError);
        connect(m_dataHandler.getParser(), &IParser::fileFormatError, this, &DataUiManager::handleFileFormatError);
    }
}

void DataUiManager::filePathChanged(const QString filePath) {
    if(filePath.isEmpty()) {
        m_dataUiHandler->setData({}, {});
    }

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
