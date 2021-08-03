#ifndef PMPC_H
#define PMPC_H

#include "common.h"
#include "points.h"

struct pmpc {

    unsigned int version;
    double distance;
    Point3D normal;
    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, distance, normal);
    }

    void display()
    {
        std::cout << version << " version \n";
        std::cout << "distance" << distance;
        std::cout << "\nnormal.x" << normal.x;
        std::cout << "\nnormal.y" << normal.y;
        std::cout << "\normal.z" << normal.z;
    }
};

#endif