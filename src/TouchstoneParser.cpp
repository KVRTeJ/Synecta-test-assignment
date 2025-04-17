#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include "../include/TouchstoneParser.h"

bool TouchstoneParser::parse() {
    QFile file(m_filePath);

    if(!_isS1PFile(m_filePath)) {
        emit fileFormatError("Incorrect file format: You can download only S1P files.");
        return false;
    }

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit fileOpenError("Can't open the file: " + m_filePath);
        return false;
    }

    m_data.clear();

    int lineNumber = 0;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if(line.isEmpty() || line[0] == '#' || line[0] == '!')
            continue;

        QStringList parts = line.split(' ', Qt::SkipEmptyParts);
        if (parts.size() != 3) {
            emit fileFormatError("Incorrect file format: in the line " + QString::number(lineNumber) + ": \n" + line);
            return false;
        }

        bool convertFrequency, convertReal, convertImag;
        double frequency = parts[0].toDouble(&convertFrequency);
        double real = parts[1].toDouble(&convertReal);
        double imag = parts[2].toDouble(&convertImag);

        if(!convertFrequency || !convertReal || !convertImag) {
            emit fileFormatError("Incorrect file format: can't convert to a number in line " + QString::number(lineNumber) + ": \n" + line);
            return false;
        }

        m_data.push_back({frequency,
                          real,
                          imag});

        ++lineNumber;
    }

    file.close();
    return true;
}

bool TouchstoneParser::_isS1PFile(const QString& filePath) {
    QFileInfo fileInfo(filePath);

    QString extension = fileInfo.suffix().toLower();

    return (extension == "s1p");
}
