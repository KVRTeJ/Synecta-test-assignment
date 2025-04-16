#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QVector>

#include "IParser.h"
#include "IProcessingData.h"

class DataHandler {
public:
    DataHandler(IParser* parser = nullptr, IProcessingData* processingUnit = nullptr);

    IProcessingData* getProcessingUnit() const {return m_processingUnit;}
    IParser* getParser() const {return m_parser;}

    void setProcessingUnit(IProcessingData* processingUnit) {m_processingUnit = processingUnit;}
    void setParser(IParser* parser) {m_parser = parser;}

    bool getProcessedData(QVector<double>& frequency, QVector<double>& logMax);

private:
    IProcessingData* m_processingUnit = nullptr;
    IParser* m_parser = nullptr;

};

#endif // DATAHANDLER_H
