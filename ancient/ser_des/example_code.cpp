#include <cereal/archives/adapters.hpp>
#include <cereal/archives/binary.hpp>
#include <cereal/types/base_class.hpp>
#include <fstream>
#include <iostream>

struct address
{
    std::string street;
    uint hno;
    char country_code;

    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(hno, country_code);
    }
};

struct Stud
{
    std::string name;
    uint roll_no;

    address house_addr;

    template <class Archive>
    void serialize(Archive &ar)
    {
        ar(roll_no, house_addr);
    }
};

std::ostream &operator<<(std::ostream &o, Stud &st)
{
    o << "\nstudent's name " << st.name << "\nroll no " << st.roll_no << "\nstreet address " << st.house_addr.street << "\n house no " << st.house_addr.hno << "\n country code " << st.house_addr.country_code << "\n";
    return o;
}

int main(int argc, char *argv[])
{
    Stud cand1;
    cand1.name = "Rakesh";
    cand1.roll_no = 1;
    cand1.house_addr.street = "boulevard street, sgr, kmr";
    cand1.house_addr.hno = 14;
    cand1.house_addr.country_code = 'K';

    // Serialize it

    std::ofstream out01;
    {
        out01.open("out.cereal", std::ios::binary);
        cereal::BinaryOutputArchive archive(out01);
        archive(cand1);
    }

    std::cout << cand1;

    out01.close();

    // deSerialize
    Stud cand2;
    std::ifstream in0;
    {
        in0.open("out.cereal", std::ios::in);
        cereal::BinaryInputArchive archive(in0);
        archive(cand2);
    }

    in0.close();
    std::cout << cand2;

    return 0;
}
