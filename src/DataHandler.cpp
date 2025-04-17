#include "../include/DataHandler.h"

DataHandler::DataHandler(const QString& filePath, IParser* parser, IProcessingData* processingUnit)
    : m_filePath(filePath), m_processingUnit(processingUnit)
{
    setParser(parser);
}

void DataHandler::setFilePath(const QString& filePath) {
    m_filePath = filePath;
    if(m_parser)
        m_parser->setFilePath(filePath);
}

void DataHandler::setParser(IParser* parser) {
    if(!parser)
        return;

    m_parser = parser;
    if(m_parser->getFilePath().isEmpty() || !m_filePath.isEmpty())
        m_parser->setFilePath(m_filePath);
    else if(m_filePath.isEmpty())
        m_filePath = m_parser->getFilePath();
}

bool DataHandler::getProcessedData(QVector<double>& frequency, QVector<double>& logMax) {
    if(!m_parser || !m_processingUnit) {
        return false;
    }

    if(!m_parser->parse())
        return false;

    QList<IParser::ParseData> parsedData = m_parser->getParsedData();
    if(parsedData.empty())
        return true;

    frequency.resize(parsedData.size());
    logMax.resize(parsedData.size());

    //If multithreading add a mutex!!!
    auto it = parsedData.begin();
    for(int i = 0; i < logMax.size(); ++it, ++i) {
        frequency[i] = it->frequency;
        logMax[i] = m_processingUnit->processData(it->real, it->imag);
    }

    return true;
}
