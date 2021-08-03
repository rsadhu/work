#ifndef PBAS_H
#define PBAS_H

#include "common.h"
#include "points.h"

struct pbas {
    unsigned int version;
    Point3D p;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, p);
    }

    void display()
    {
        std::cout << version << " version \n";
        std::cout << p.x << " x \n";
        std::cout << p.y << " y \n";
        std::cout << p.z << " z \n";
    }
};

#endif