#ifndef PCVI_H
#define PCVI_H

#include "common.h"
#include "points.h"

struct pcvi {

    unsigned int version;
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
        std::cout << "\n version " << version;
        std::cout << "\n efl " << efl;
        std::cout << "\n forwardDistortionCoeffs ";
        for (int i = 0; i < 8; i++) {
            std::cout << forwardDistortionCoeffs[i] << " ";
        }

        std::cout << "\n inverseDistortionCoeffs ";
        for (int i = 0; i < 8; i++) {
            std::cout << inverseDistortionCoeffs[i] << " ";
        }

        std::cout << "\n undistortLUT ";
        for (int i = 0; i < 256; i++) {
            std::cout << undistortLUT[i] << " ";
        }

        std::cout << "\n distortLUT ";
        for (int i = 0; i < 256; i++) {
            std::cout << distortLUT[i] << " ";
        }

        std::cout << "\n principalPoint " << principalPoint.x << " " << principalPoint.y;
    }
};
#endif