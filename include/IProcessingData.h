#ifndef IPROCESSINGDATA_H
#define IPROCESSINGDATA_H

class IProcessingData {
public:
    virtual ~IProcessingData() = default;

    virtual double processData(const double real, const double imag) = 0;
};

#endif // IPROCESSINGDATA_H
