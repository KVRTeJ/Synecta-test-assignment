#include <iostream>
#include <QDebug>

#include "TouchstoneParser.h"
#include "ProcessingLogMag.h""

int main(int argc, char *argv[]) {
    ProcessingLogMag foo;
    foo.processData(-0.78411, -0.665123);
    return -2;
    TouchstoneParser boo;

    boo.setFileName("C:\\Users\\dmitriy.filimonov\\Downloads\\S11.S1P");
    boo.parse();

    auto parsed = boo.getParsedData();
    qDebug() << parsed.size();
    for(auto it = parsed.begin(); it != parsed.end(); ++it) {
        qDebug() << (*it).frequency << (*it).real << (*it).imag;
    }

    return -1;
}
