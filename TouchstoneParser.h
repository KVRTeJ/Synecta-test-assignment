#ifndef TOUCHSTONEPARSER_H
#define TOUCHSTONEPARSER_H

#include "IParser.h"

class TouchstoneParser : public IParser {
public:
    TouchstoneParser(const QString& filePath = "") : m_filePath(filePath)
    {}
    ~TouchstoneParser() override = default;

    QString getFilePath() const override {return m_filePath;}
    void setFilePath(const QString& filePath) override {m_filePath = filePath;}

    bool parse() override;

    QList<ParseData> getParsedData() const override {return m_data;}

private:
    QString m_filePath = "";
    QList<ParseData> m_data = {};
};

#endif // TOUCHSTONEPARSER_H
