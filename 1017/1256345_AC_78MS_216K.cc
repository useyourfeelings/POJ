#include<iostream>
int main()
{
    long long b1, b2, b3, b4, b5, b6, count, t;
    while(std::cin>>b1>>b2>>b3>>b4>>b5>>b6)
    {
        if(b1 == 0 && b2 == 0 && b3 == 0 &&
           b4 == 0 && b5 == 0 && b6 == 0) break;
        t = (b3 == 0) ? 0 : ((b3 - 1) / 4 + 1);
        count = b4 + b5 + b6 + t;
        if(b3 % 4 == 0) t = b2 - 5 * b4;
        else t = b2 - (5 * b4 + 7 - 2 * (b3 % 4));
        if(t > 0) count += ((t - 1) / 9 + 1);
        if((t = b1 - (36 * count - b2 * 4 - b3 * 9 - b4 * 16 - b5 * 25 - b6 * 36)) > 0)
        count += ((t - 1) / 36 + 1);
        std::cout<<count<<std::endl;
    }
    return 0;
}