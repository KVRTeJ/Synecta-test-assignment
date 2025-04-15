#ifndef TOUCHSTONEPARSER_H
#define TOUCHSTONEPARSER_H

#include "IParser.h"

class TouchstoneParser : public IParser {
public:
    TouchstoneParser(const QString& fileName = "") : m_fileName(fileName)
    {}
    ~TouchstoneParser() override = default;

    QString getFileName() const override {return m_fileName;}
    void setFileName(const QString& fileName) override {m_fileName = fileName;}

    bool parse() override;

    QList<ParseData> getParsedData() const override {return m_data;}

private:
    QString m_fileName = "";
    QList<ParseData> m_data = {};
};

#endif // TOUCHSTONEPARSER_H
