#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QVector>

#include "IParser.h"
#include "IProcessingData.h"

class DataHandler {
public:
    DataHandler(const QString& fileName = "", IParser* parser = nullptr, IProcessingData* processingUnit = nullptr);

    QString getFileName() const {return m_fileName;}
    IProcessingData* getProcessingUnit() const {return m_processingUnit;}
    IParser* getParser() const {return m_parser;}

    void setFileName(const QString& fileName);
    void setProcessingUnit(IProcessingData* processingUnit) {m_processingUnit = processingUnit;}
    void setParser(IParser* parser);

    bool getProcessedData(QVector<double>& frequency, QVector<double>& logMax);

private:
    QString m_fileName = "";
    IProcessingData* m_processingUnit = nullptr;
    IParser* m_parser = nullptr;
};

#endif // DATAHANDLER_H
