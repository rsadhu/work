#ifndef H11_PDCL_ENTRY_H
#define H11_PDCL_ENTRY_H
#include "common.h"

struct h11_pdcl_entry {

    int type;

    short int dcMinDx;

    short int dcMaxDx;

    short int dcMinDy;

    short int dcMaxDy;

    short int dxcShift;
    short int refOffsetX;

    short int refOffsetY;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(type, dcMinDx, dcMaxDx, dcMinDy, dcMaxDy, dxcShift, refOffsetX, refOffsetY);
    }

    void display()
    {
        // std::cout << "\n type " << getType(type);
        std::cout << "\n dcMinDx " << dcMinDx;
        std::cout << "\n dcMaxDx " << dcMaxDx;

        std::cout << "\n dcMinDy " << dcMinDy;
        std::cout << "\n dcMaxDy " << dcMaxDy;

        std::cout << "\n refOffsetX " << refOffsetX;
        std::cout << "\n refOffsetY " << refOffsetY;
    }
};

#endif //