#include <QFile>
#include <QDebug>

#include "TouchstoneParser.h"

bool TouchstoneParser::parse() {
    QFile file(m_fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "cant open file" << m_fileName;
        return false;
    }

    ParseData currentData;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        if (line.isEmpty()) {
            continue;
        }

        if(line[0] == '#' || line[0] == '!')
            continue;

        QStringList parts = line.split(' ', Qt::SkipEmptyParts);
        if (parts.size() != 3) {
            qDebug() << "uncorrect format file: has" << parts.size() << "in line:" << line;
            file.close();
            return false;
        }

        bool convertFrequency, convertReal, convertImag;
        double frequency = parts[0].toDouble(&convertFrequency);
        double real = parts[1].toDouble(&convertReal);
        double imag = parts[2].toDouble(&convertImag);

        if(!(convertFrequency && convertReal && convertImag)) {
            qDebug() << "uncorrect format file: cant convert to double" << "in line:" << line;
            file.close();
            return false;
        }

        currentData.frequency = frequency;
        currentData.real = real;
        currentData.imag = imag;

        m_data.push_back(currentData);
    }

    for(auto it = m_data.begin(); it != m_data.end(); ++it) {
        qDebug() << (*it).frequency << (*it).real << (*it).imag;
    }
    file.close();
    return true;
}
