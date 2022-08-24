/* MyMEXFunction
 * Adds second input to each
 * element of first input
 * a = MyMEXFunction(a,b);
 */

#include "lzmacodec.h"
#include "mex.hpp"
#include "mexAdapter.hpp"

using namespace matlab::data;
using matlab::mex::ArgumentList;

class MexFunction : public matlab::mex::Function
{
public:
    void operator()(ArgumentList outputs, ArgumentList inputs)
    {

        auto imageCell = inputs[0];
        TypedArrayRef<MATLABString> inArrayRef1 = imageCell[0];

        std::string src_file_with_path = std::string(inArrayRef1[0]);
        std::cout << "\n src path " << src_file_with_path << "\n";

        TypedArrayRef<MATLABString> inArrayRef2 = imageCell[1];
        std::string target_file_with_path = std::string(inArrayRef2[0]);

        std::cout << "\n taregt path " << src_file_with_path << "\n";

        TypedArrayRef<MATLABString> inArrayRef3 = imageCell[2];
        std::string operation = std::string(inArrayRef3[0]);

        if (operation == "compress")
        {
            compress(src_file_with_path, target_file_with_path);
        }
        else if (operation == "decompress")
        {
            decompress(src_file_with_path, target_file_with_path);
        }
        else
        {
            std::cout << "\n wrong argument\n";
        }
    }
};
