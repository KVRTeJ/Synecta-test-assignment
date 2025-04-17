#include "DataUiManager.h"

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
