#include <iostream>
#include <QDebug>
#include <assert.h>

#include "TouchstoneParser.h"
#include "ProcessingLogMag.h"
#include "DataHandler.h"

int main(int argc, char *argv[]) {
    TouchstoneParser pars;
    pars.setFileName("C:\\Users\\dmitriy.filimonov\\Downloads\\samples500k.S1P");
    pars.parse();

    ProcessingLogMag proc;

    DataHandler hand("C:\\Users\\dmitriy.filimonov\\Downloads\\S11.S1P");
    hand.setParser(&pars);
    hand.setProcessingUnit(&proc);

    QVector<double> xAxis, yAxis;
    hand.getProcessedData(xAxis, yAxis);

    assert(xAxis.size() == yAxis.size());

    qDebug() << xAxis.size() << yAxis.size();
//    qDebug() << xAxis;
//    qDebug() << "================================================================================";
//    qDebug() << yAxis;

    return -1;
}
