#ifndef PROCESSINGLOGMAG_H
#define PROCESSINGLOGMAG_H

#include "IProcessingData.h"

class ProcessingLogMag : public IProcessingData {
public:
    ProcessingLogMag() = default;
    ~ProcessingLogMag() override = default;

    double processData(const double real, const double imag) override;
};

#endif // PROCESSINGLOGMAG_H
