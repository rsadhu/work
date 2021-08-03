#ifndef PCVE_H
#define PCVE_H

#include "common.h"
#include "points.h"

struct pcve {
    unsigned int version;
    double rotMatrix[3][3];
    Point3D focalPoint;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, rotMatrix, focalPoint);
    }

    void display()
    {
        std::cout << "\n version " << version;
        std::cout << "\n rotMatrix " << version;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << rotMatrix[i][j] << " ";
            }
        }

        std::cout << "\n focalPoint " << focalPoint.x << " " << focalPoint.y << " " << focalPoint.z << "\n";
    }
};

#endif