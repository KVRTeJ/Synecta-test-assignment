#include <math.h>
#include <QDebug>

#include "ProcessingLogMag.h"

double ProcessingLogMag::processData(const double real, const double imag) {
    double result = pow(real, 2) + pow(imag, 2);

    qDebug() << real << pow(real, 2) << imag << pow(imag, 2);

    return result;
}
