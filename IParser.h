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

    virtual QString getFileName() const = 0;
    virtual void setFileName(const QString& fileName) = 0;

    virtual bool parse() = 0;

    virtual QList<ParseData> getParsedData() const = 0;
};

#endif // IPARSER_H
