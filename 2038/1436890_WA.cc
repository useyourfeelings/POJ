#include<iostream>
#include<algorithm>
using namespace std;

char g[100][6];

int main()
{
    int i, j, k, f, t, pos, sum, minsum;
    while(scanf("%d", &t) && t != 0)
    {
        getchar();
        for(i = 0; i < t; ++ i) gets(g[i]);
        char test[6] = {'A', 'B', 'C', 'D', 'E', '\0'};
        char answer[6];
        minsum = 1000000;
        for(;;)
        {
            for(i = sum = 0; i < t; ++ i)
            {
                for(j = 0; j < 4; ++ j)
                {
                    pos = 0;
                    while(test[pos] != g[i][j]) ++ pos;
                    for(k = j + 1; k < 5; ++ k)
                    {
                        for(f = 0; f <= pos; ++ f) if(test[f] == g[i][k]) break;
                        if(f <= pos) ++ sum;
                    }
                }
            }
            if(sum < minsum)
            {
                for(i = 0; i < 6; ++ i) answer[i] = test[i];
                minsum = sum;
            }
            if(!next_permutation(test, test + 5)) break;
        }
        printf("%s is the median ranking with value %d\n", answer, minsum);
    }
    return 0;
}