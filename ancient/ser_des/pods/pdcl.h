#ifndef PDCL_H
#define PDCL_H

#include "common.h"
#include "h11_pdcl_entry.h"

struct pdcl {
    uint version;
    uint8_t numEntries;
    h11_pdcl_entry entry[4];

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, numEntries, entry);
    }

    void display()
    {
        std::cout << "\n version " << version;
        std::cout << "\n numEntries " << numEntries;
        for (int i = 0; i < 4; i++) {
            entry[i].display();
        }
    }
};

#endif
