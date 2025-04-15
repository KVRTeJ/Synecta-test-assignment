#include <iostream>
#include <QDebug>

#include "TouchstoneParser.h"

int main(int argc, char *argv[]) {
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
