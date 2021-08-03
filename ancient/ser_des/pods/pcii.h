#ifndef PCII_H
#define PCII_H

#include "common.h"
#include "points.h"

struct pcii {
    unsigned int version = 1;
    double efl;
    Point2D principalPoint;
    double undistortLUT[256];
    double distortLUT[256];
    double forwardDistortionCoeffs[8];
    double inverseDistortionCoeffs[8];

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, efl, principalPoint, undistortLUT, distortLUT, forwardDistortionCoeffs, inverseDistortionCoeffs);
    }

    void display()
    {
        std::cout << " version " << version << "\n";
        std::cout << " efl " << efl << "\n";
        std::cout << " principalPoint " << principalPoint.x << "  " << principalPoint.y << "\n";
        std::cout << " undistortLUT \n";
        for (int i = 0; i < 256; i++) {
            std::cout << undistortLUT[i];
        }

        std::cout << " \nforwardDistortionCoeffs \n";
        for (int i = 0; i < 8; i++) {
            std::cout << forwardDistortionCoeffs[i] << " ";
        }

        std::cout << "\n inverseDistortionCoeffs \n";
        for (int i = 0; i < 8; i++) {
            std::cout << inverseDistortionCoeffs[i] << " ";
        }
    }
};

#endif //