#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[])
{
    if (argc==3)
    {
        std::string cmd (argv[1]);
        std::string load(argv[2]);
        if (cmd =="--dec")
        {
            
        }
        else
        if (cmd == "--bin")
        {
            std::string tmp;
            int actual_load = std::stoi(load);
            while(actual_load)
            {
                tmp.append(std::to_string(actual_load%2));
                actual_load/=2;
            }
            std::reverse(tmp.begin(), tmp.end());
            std::cout<<tmp<<"\n";
        }
        else
        {
            std::cout<<"wrong args";
        }
    }
    else if (argc == 2)
    {
        std::string help("--help");
        if (argv[1] == help)
        {
            std::cout<<" bin_dec --dec 100100111\n";
            std::cout<<" bin_dec --bin 212 \n";
        }
        else
        {
            std::cout<<"wrong choice \n";
        }
    }
    else
    {
        std::cout<<" Insufficient Args";

    }

 return 0;
}
