#include "pbas.h"
#include "pcic.h"
#include "pcii.h"
#include "pcvc.h"
#include "pcve.h"
#include "pcvi.h"
#include "pdcl.h"
#include "pmpc.h"
#include "preg.h"
#include "prf1.h"
#include "prf2.h"

// using namespace Afdr;

// void test_pbas(std::string file_name)
// {
//     Serializer<pbas> myData;
//     myData.start_serialization(file_name);
// }

// void test_pcic(std::string file_name)
// {
//     Serializer<pcic> myData;
//     myData.start_serialization(file_name);
// }

// void test_pcii(std::string file_name)
// {
//     Serializer<pcii> myData;
//     myData.start_serialization(file_name);
// }

// void test_pcvc(std::string file_name)
// {
//     Serializer<pcvc> myData;
//     myData.start_serialization(file_name);
// }

// void test_pcve(std::string file_name)
// {
//     Serializer<pcve> myData;
//     myData.start_serialization(file_name);
// }

// void test_pcvi(std::string file_name)
// {
//     Serializer<pcvi> myData;
//     myData.start_serialization(file_name);
// }

// void test_pdcl(std::string file_name)
// {
//     Serializer<pdcl> myData;
//     myData.start_serialization(file_name);
// }

// void test_pmpc(std::string file_name)
// {
//     Serializer<pmpc> myData;
//     myData.start_serialization(file_name);
// }

// void test_preg(std::string file_name)
// {
//     Serializer<preg> myData;
//     myData.start_serialization(file_name);
// }

void test_prf1()
{
    std::string file = "prf1.bin";
    prf1 aa;
    aa.version = 10;
    aa.numEntries = 3;
    aa.refMarginLeft = 20;
    aa.refMarginRight = 30;
    for (int i = 0; i < 16; i++)
        aa.uuid[i] = (uint8_t)65 + i;

    for (int i = 0; i < 3; i++) {
        aa.entry[i].resX = 40;
        aa.entry[i].resY = 50;
        aa.entry[i].packedSize = 10;
        aa.entry[i].type = h11_referenceProjectorType(1);

        for (int j = 0; j < 12; j++)
            aa.entry[i].refTemperature[j] = 10 + j;

        uint8_t* data = new uint8_t[aa.entry[i].packedSize];

        for (int k = 0; k < aa.entry[i].packedSize; k++) {
            data[k] = (93 + k);
        }

        std::shared_ptr<uint8_t> d(data);
        aa.entry[i].refData = d;
    }

    start_serialization(aa, file);

    prf1 mydata;
    start_deserialization(mydata, file);
}

// void test_prf2(std::string file_name)
// {
//     Serializer<prf2> myData;
//     myData.start_deserialization(file_name);
// }

int main(int argc, char* argv[])
{

    

    //test_pbas(file_name);
    //test_pcic(file_name);
    //test_pcii(file_name);
    //test_pcvc(file_name);
    ///test_pcve(file_name);
    //test_pcvi(file_name);
    //test_pdcl(file_name);
    //test_pmpc(file_name);
    //test_preg(file_name);
    test_prf1();
    //test_prf2(file_name);

    return 0;
}
