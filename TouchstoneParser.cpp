#include <QFile>
#include <QDebug>

#include "TouchstoneParser.h"

bool TouchstoneParser::parse() {
    QFile file(m_fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "cant open file" << m_fileName;
        return false;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();

        qDebug() << line;
    }

}
