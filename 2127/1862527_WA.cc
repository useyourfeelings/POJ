#include<iostream>
using namespace std;

int a[500], b[500], next[500];
int record[500][500];
int aSize, bSize, i, j, head = -1, ans = 0;

int main()
{
    scanf("%d", &aSize);
    for(i = 0; i < aSize; ++ i)
    {
        scanf("%d", &a[i]);
        next[i] = -1;
    }
    scanf("%d", &bSize);
    for(i = 0; i < bSize; ++ i) scanf("%d", &b[i]);
    for(i = 0; i < aSize; ++ i)
        for(j = 0; j < bSize; ++ j) record[i][j] = -1;
    
    int max, t, k, who;
    
    
    for(i = aSize - 1; i >= 0; -- i)
    {
        for(j = bSize - 1; j >= 0; -- j)
        {
            if(a[i] != b[j]) continue;
            record[i][j] = 1;
            max = 0;
            for(t = i + 1; t < aSize; ++ t)
            {
                if(a[t] <= a[i]) continue;
                for(k = j + 1; k < bSize; ++ k)
                {
                    if(a[t] != b[k]) continue;
                    if(record[t][k] > max)
                    {
                         max = record[t][k];
                         who = t;
                    }
                }
            }
            record[i][j] += max;
            if(max == 0) next[i] = -1;
            else         next[i] = who;
            if(record[i][j] > ans)
            {
                ans = record[i][j];
                head = i;
            }
        }
    }
    
    printf("%d\n", ans);
    if(ans)
    {
        do
        {
            printf("%d ", a[head]);
            head = next[head];
        }
        while(head != -1);
    }
    return 0;
}