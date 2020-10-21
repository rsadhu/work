#include <iostream>
#include "someheader.h"
#include <openssl/ssl.h>
#include <openssl/ossl_typ.h>


uint log(uint base, uint number)
{
    uint cnt = 0;
    if ( number < base)
        return 1;

    while(base)
    {
        cnt++;
        number /= base;
    }
    return cnt;
}

double pow(double base, double exp)
{
    if (exp == 0)
        return 1;
    return base * pow(base , --exp);
}


int main() {

SSL *ssl = nullptr;
void *buf ;
int num = 9;

SSL_read(ssl, buf, num);

std::cout << "Hello, World!   " << " \n";
    //auto t =  sum(1, 9);
//    std::cout<<" sum -> "<<t<<"\n";

    for (uint i = 1; i< 100;i++) {
        std::cout << " pow = "<<pow(i, i) << " log = " << log(10,pow(i,i))<<"\n";
    }
    return 0;
}
