#ifndef POINTS_H
#define POINTS_H

#include "common.h"

struct Point2D {
    double x, y;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(x, y);
    }
};

struct Point3D {
    double x, y, z;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(x, y, z);
    }
};

#endif //