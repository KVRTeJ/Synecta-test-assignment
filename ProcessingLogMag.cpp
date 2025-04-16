#include <math.h>
#include <QDebug>

#include "ProcessingLogMag.h"

double ProcessingLogMag::processData(const double real, const double imag) {
    double result = pow(real, 2) + pow(imag, 2);

    result = sqrt(result);

    result = 20 * log10(result);

    qDebug() << result;

    return result;
}
