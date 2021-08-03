#ifndef PCIC_H
#define PCIC_H

#include "common.h"

struct pcic {
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
        std::cout << " version " << version << "\n";
        std::cout << " resX " << resX << "\n";
        std::cout << " resY " << resY << "\n";
        std::cout << " pixelSize " << pixelSize << "\n";
        std::cout << " sensorTemperature " << sensorTemperature << "\n";
        std::cout << " eflCoeffs " << eflCoeffs[0] << " :: " << eflCoeffs[1] << "\n";
    }
};

#endif