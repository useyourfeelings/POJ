#include<iostream>
using namespace std;

int s[26], e[26];

int main()
{
    int i, n, t, start, end, sum;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d", &t);
        getchar();
        for(i = 0, start = 1001, end = -1; i < t; ++ i)
        {
            getchar();
            scanf("%d%d", &s[i], &e[i]);
            getchar();
            if(s[i] < start) start = s[i];
            if(e[i] > end) end = e[i];
        }
        for(; start < end; ++ start)
        {
            for(i = sum = 0; i < t; ++ i)
                if(s[i] <= start && start < e[i]) ++ sum;
            if(sum != 0) printf("%c", sum + 64);
        }
        printf("\n");
    }
    return 0;
}
