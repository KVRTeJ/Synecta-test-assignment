#include <QDebug>

#include "DataHandler.h"

DataHandler::DataHandler(const QString& fileName, IParser* parser, IProcessingData* processingUnit)
    : m_fileName(fileName), m_processingUnit(processingUnit)
{
    setParser(parser);
}

void DataHandler::setFileName(const QString& fileName) {
    m_fileName = fileName;
    if(m_parser)
        m_parser->setFileName(fileName);
}

void DataHandler::setParser(IParser* parser) {
    if(!parser)
        return;

    m_parser = parser;
    if(m_parser->getFileName().isEmpty() || !m_fileName.isEmpty())
        m_parser->setFileName(m_fileName);
    else if(m_fileName.isEmpty())
        m_fileName = m_parser->getFileName();
}

bool DataHandler::getProcessedData(QVector<double>& frequency, QVector<double>& logMax) {
    if(!m_parser || !m_processingUnit) {
        //TODO: emit
        return false;
    }

    if(!m_parser->parse())
        return false;

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
