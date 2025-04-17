
#include <QFile>
#include <QDebug>

#include "TouchstoneParser.h"

bool TouchstoneParser::parse() {
    QFile file(m_filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "cant open file" << m_filePath; //TODO: to emit
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
            qDebug() << "uncorrect format file: has" << parts.size() << "in line:" << line; //TODO: to emit
            return false;
        }

        bool convertFrequency, convertReal, convertImag;
        double frequency = parts[0].toDouble(&convertFrequency);
        double real = parts[1].toDouble(&convertReal);
        double imag = parts[2].toDouble(&convertImag);

        if(!convertFrequency || !convertReal || !convertImag) {
            qDebug() << "uncorrect format file: cant convert to double" << "in line:" << line; //TODO: to emit
            return false;
        }

        m_data.push_back({frequency,
                          real,
                          imag});

    }

    file.close();
    return true;
}
