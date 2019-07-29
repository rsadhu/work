#pragma once



int countBits(int a)
{
    int cnt = 0;
    while(a)
    {
        a & 1 ? cnt++ : 0;
        a>>=1;
    }
    return cnt;
}
