#include <QCoreApplication>
#include<iostream>
using namespace std;

void test()
{
    int n=10;
    //cin>>n;

    char *str = new char[n]();
    strcpy(str,"www.abc.xy");
//    cin>>str;

    int drft=87;


    char *tmp =  str;
    while(*str!='\0')
    {
            drft =  drft%26;
             if(*str=='.')
             {
                 str++;
                 continue;
             }
            unsigned  char ch =  *str+ drft;
            if(ch>'z')
            {
                ch = ch % 122;
                ch += 96;
            }
            else if(ch <'a' && ch>'Z')
            {
                ch = ch % 90;
                ch += 65;
            }

        *str=ch;
        str++;
    }
    cout<<tmp<<endl;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    test();
    return a.exec();
}

