#ifndef TOUCHSTONEPARSER_H
#define TOUCHSTONEPARSER_H

#include "IParser.h"

class TouchstoneParser : public IParser {
public:
    TouchstoneParser();
    ~TouchstoneParser() override = default;

    QString getFileName() const override;
    void setFileName(const QString& fileName) override;

    bool parse() override;

    QList<ParseData> getParsedData() const override;

private:
    QString m_fileName = 0;
    QList<ParseData> m_data = {};
};

#endif // TOUCHSTONEPARSER_H
