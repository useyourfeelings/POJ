#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int i, j, n, n1, n2, sz, k, answer;
    char t;
    scanf("%d", &n);
    getchar();
    while(n --)
    {
        vector<int> d;
        while(scanf("%c", &t))
        {
            if(t == '\n') break;
            if(t == ' ') continue;
            d.push_back(int(t) - 48);
        }
        sz = d.size();
        if(sz % 2)
        {
            if(d[0] == 0) swap(d[0], d[1]);
            j = sz / 2;
            n1 = n2 = 0;
            for(i = 0; i <= j; ++ i)
                n1 += pow(10.0, j - i) * d[i];
            ++ j;
            for(; i < sz; ++ i) n2 += pow(10.0, i - j) * d[i];
            answer = n1 - n2;
        }
        else
        {
            if(sz == 2) answer = d[1] - d[0];
            else
            {
                answer = 1000000;
                int mind = 10;
                if(d[0] == 0) i = 2;
                else i = 1;
                for(; i < sz; ++ i)
                {
                    if(d[i] - d[i - 1] <= mind)
                    {
                        mind = d[i] - d[i - 1];
                        n1 = pow(10.0, sz / 2 - 1) * d[i];
                        n2 = pow(10.0, sz / 2 - 1) * d[i - 1];
                        for(j = sz / 2 - 2, k = 0; j >= 0; -- j)
                        {
                            if(k == i - 1) k += 2;
                            n1 += pow(10.0, j) * d[k];
                            ++ k;
                        }
                        for(j = 0; j <= sz / 2 - 2; ++ j)
                        {
                            if(k == i - 1) k += 2;
                            n2 += pow(10.0, j) * d[k];
                            ++ k;
                        }
                    }
                    if((n1 - n2) < answer) answer = n1 - n2;
                }
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}