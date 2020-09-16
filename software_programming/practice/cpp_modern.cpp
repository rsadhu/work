#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> lu;
    lu[0] = "Rakesh";
    lu[1] = "Ashwani";
    lu[2] = "Jotika";
    lu[3] = "Mummy";
    lu[4] = "Daddy";

    for(auto &[key, value]: lu)
    {
        std::cout<<key << "  ::  "<< value<<" \n ";
    }
    return 0;
}



