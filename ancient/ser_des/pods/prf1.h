#ifndef PRF1_H
#define PRF1_H

#include "common.h"

struct h11_prf_entry {

    h11_referenceProjectorType type;
    h11_referenceFormatDR formatDR;
    h11_referenceFormatPacked formatPacked;
    uint16_t numRefs;
    uint32_t packedSize = 0;
    uint16_t resX;
    uint16_t resY;
    double refTemperature[12];
    std::shared_ptr<uint8_t> refData;

    //  std::vector<uint8_t> v_data;

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(type, formatDR, formatPacked, numRefs, packedSize, resX, resY, refTemperature);

        std::shared_ptr<uint8_t> ptr_refdata(new uint8_t[packedSize]);
        refData = std::move(ptr_refdata);
        ar(refData);
    }

    void display()
    {
        // std::cout<<"\n type " << static_cast<h11_referenceProjectorType> (type);
        // std::cout<<"\n formatDR " << static_cast<h11_referenceFormatDR> (formatDR);
        // std::cout<<"\n formatPacked " << static_cast<h11_referenceFormatPacked> (formatPacked);

        std::cout << "\n numRefs " << numRefs;
        std::cout << "\n packedSize " << packedSize;
        std::cout << "\n resX " << resX;
        std::cout << "\n resY " << resY;

        for (int i = 0; i < 12; i++)
            std::cout << refTemperature[i] << " ";

        for (int i = 0; i < packedSize; i++) {
            std::cout << refData.get()[i] << " ";
        }
    }
};

struct prf1 {

    unsigned int version;
    uint16_t uuid[16];

    uint8_t refMarginLeft;
    uint8_t refMarginRight;
    uint8_t numEntries;
    h11_prf_entry entry[3];

    template <class Archive>
    void serialize(Archive& ar)
    {
        ar(version, uuid, refMarginLeft, refMarginRight, numEntries, entry);
    }

    void display()
    {
        //not implemented
    }
};

#endif