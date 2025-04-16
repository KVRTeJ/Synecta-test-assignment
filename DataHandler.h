#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QVector>

#include "IParser.h"
#include "IProcessingData.h"

class DataHandler {
public:
    DataHandler(const QString& filePath = "", IParser* parser = nullptr, IProcessingData* processingUnit = nullptr);

    QString getFilePath() const {return m_filePath;}
    IProcessingData* getProcessingUnit() const {return m_processingUnit;}
    IParser* getParser() const {return m_parser;}

    void setFilePath(const QString& fileName);
    void setProcessingUnit(IProcessingData* processingUnit) {m_processingUnit = processingUnit;}
    void setParser(IParser* parser);

    bool getProcessedData(QVector<double>& frequency, QVector<double>& logMax);

private:
    QString m_filePath = "";
    IProcessingData* m_processingUnit = nullptr;
    IParser* m_parser = nullptr;
};

#endif // DATAHANDLER_H
