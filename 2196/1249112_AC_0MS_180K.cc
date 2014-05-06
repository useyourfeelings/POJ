#include<iostream>
using namespace std;

int main()
{   
    int i, d, h, dd;
    for(i = 2992; i < 10000; i++)
    {
        d = i / 1000;
        d += i % 1000 / 100;
        d += i % 1000 % 100 / 10;
        d += i % 1000 % 100 % 10;
        dd = i / 1728;
        dd += i % 1728 / 144;
        dd += i % 1728 % 144 / 12;
        dd += i % 1728 % 144 % 12;
        if(d != dd) continue;
        h = i / 4096;
        h += i % 4096 / 256;
        h += i % 4096 % 256 / 16;
        h += i % 4096 % 256 % 16;
        if(d != h) continue;
        cout<<i<<endl;
    }
    return 0;
}