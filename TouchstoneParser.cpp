
#include <QFile>
#include <QDebug>

#include "TouchstoneParser.h"

bool TouchstoneParser::parse() {
    QFile file(m_filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        emit fileOpenError("can't open the file: " + m_filePath);
        return false;
    }

    m_data.clear();

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if(line.isEmpty() || line[0] == '#' || line[0] == '!')
            continue;

        QStringList parts = line.split(' ', Qt::SkipEmptyParts);
        if (parts.size() != 3) {
            emit fileFormatError("incorrect file format: in the line: " + line);
            return false;
        }

        bool convertFrequency, convertReal, convertImag;
        double frequency = parts[0].toDouble(&convertFrequency);
        double real = parts[1].toDouble(&convertReal);
        double imag = parts[2].toDouble(&convertImag);

        if(!convertFrequency || !convertReal || !convertImag) {
            emit fileFormatError("Incorrect file format: could not be converted to a number in a string: " + line);
            return false;
        }

        m_data.push_back({frequency,
                          real,
                          imag});

    }

    file.close();
    return true;
}
