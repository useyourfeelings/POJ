#include<iostream>
#include<string>
using namespace std;

int main()
{
    int g[9];
    int i, k;
    while(scanf("%d", &g[0]) != EOF)
    {
        string poly;
        for(i = 1; i < 9; ++ i) scanf("%d", &g[i]);
        for(i = 0; i < 9; ++ i)
        {
            if(g[i] == 0) continue;
            if(g[i] < 0)
            {
                if(poly.empty()) poly += "-";
                else             poly += " - "; 
                g[i] = - g[i];
            }
            else
            {
                if(!poly.empty()) poly += " + ";
            }
            if(g[i] != 1)
            {
                k = 100;
                while(g[i] / k == 0) k /= 10;
                while(k >= 1)
                {
                    poly += char(g[i] / k + 48);
                    g[i] %= k;
                    k /= 10;
                }
            }
            else
            {
                if(i == 8) poly += "1";
            }
            if(i < 8) poly += "x";
            if(i < 7)
            {
                poly += '^';
                poly += char(56 - i);
            }
        }
        if(poly.empty()) poly += '0';
        cout<<poly<<"\n";
    }
    return 0;
}