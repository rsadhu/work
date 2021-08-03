#ifndef PCVC_H
#define PCVC_H

#include "common.h"

struct pcvc {
    unsigned int version;
    uint16_t resX;
    uint16_t resY;
    double pixelSize;
    double sensorTemperature;
    double eflCoeffs[2];

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, resX, resY, pixelSize, sensorTemperature, eflCoeffs);
    }

    void display()
    {
        std::cout << "\n version " << version;
        std::cout << "\n resX " << resX;
        std::cout << "\n resY " << resY;
        std::cout << "\n pixelSize " << pixelSize;
        std::cout << "\n sensorTemperature " << sensorTemperature;
        std::cout << "\n eflCoeffs[0] " << eflCoeffs[0];
        std::cout << "\n eflCoeffs[0] " << eflCoeffs[1];
    }
};
#endif