#include <iostream>
#include <cstring>

class Rule_3_5
{

    public:
        Rule_3_5()
        {
            m_data = new char [s_size];
            std::strcpy(m_data , "RakeshSadhu");
        }


        Rule_3_5(const Rule_3_5 &rhs)
        {
            if (this->m_data!=nullptr)
                this->~Rule_3_5();

            m_data = new char[s_size];

            std::strcpy(this->m_data, rhs.m_data);
        }

        Rule_3_5(Rule_3_5 &&rhs)
        {
            this->~Rule_3_5();
            m_data = rhs.m_data;

        }

        ~Rule_3_5()
        {

            delete []m_data;
            m_data = nullptr;

        }

    private:
        char *m_data =  nullptr;
        static constexpr size_t s_size{12};
};


void test(Rule_3_5 &r)
{
    Rule_3_5 s = r;
}


int main(void)
{
    std::cout<<"\nmain starts\n";
    Rule_3_5 r;
    //Rule_3_5 s = r;

    test(r);
    std::cout<<"\n main ends\n";
    return 0;
}