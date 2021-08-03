#ifndef PRF2_H
#define PRF2_H

#include "common.h"

struct h11_prf2_entry {

    h11_referenceProjectorType type;
    h11_referenceFormatDR formatDR;
    h11_referenceFormatPacked formatPacked;
    uint8_t refMarginIRLeft;
    uint8_t refMarginIRRight;
    uint8_t refMarginIRTop;
    uint8_t refMarginIRBottom;
    uint16_t numRef;
    uint packedSize;
    uint16_t resX;
    uint16_t resY;
    double refTemperature[12];
    //std::vector<uint8_t> refData;
    std::shared_ptr<uint8_t[]> refData;
    //std::array<uint8_t> refData;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(type, formatDR, formatPacked, refMarginIRLeft, refMarginIRRight, refMarginIRTop, numRef, packedSize, resX, resY, refTemperature);

        refData = std::make_shared<uint8_t>(packedSize);

        ar(refData);
    }

    void display()
    {
        // std::cout<< "Not implemented \n";
    }
};

struct prf2 {
    uint version;
    uint16_t hwtype;
    uint8_t numEntries;
    h11_prf2_entry entry[3];

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, hwtype, numEntries, entry);
    }

    void display()
    {
        // std::cout<< "Not implemented \n";
    }
};

#endif
