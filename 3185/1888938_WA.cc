#include<iostream>
using namespace std;

int bowl[20];

int main()
{
    int i, c = 0;
    for(i = 0; i < 20; ++ i) scanf("%d", &bowl[i]);
    for(i = 0; i < 20; ++ i)
    {
        if(bowl[i] == 1)
        {
            ++ c;
            bowl[i] = 0;
            bowl[i + 1] = 1 - bowl[i + 1];
            if(i + 2 < 20) bowl[i + 2] = 1 - bowl[i + 2];
        }
    }
    printf("%d", c);
    return 0;
}