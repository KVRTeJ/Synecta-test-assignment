#ifndef IPARSER_H
#define IPARSER_H

#include <QString>
#include <QList>

class IParser {
public:
    struct ParseData {
        double frequency = 0;
        double real = 0;
        double imag = 0;
    };

public:
    virtual ~IParser() = default;

    virtual QString getFilePath() const = 0;
    virtual void setFilePath(const QString& filePath) = 0;

    virtual bool parse() = 0;

    virtual QList<ParseData> getParsedData() const = 0;
};

#endif // IPARSER_H
