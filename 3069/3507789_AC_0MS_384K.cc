#include<iostream>
#include<algorithm>
using namespace std;

int T[1024];

int main()
{
    int R, N, i, head, total;
    while(scanf("%d%d", &R, &N) && R != -1)
    {
        for(i = 0; i < N; ++ i) scanf("%d", &T[i]);
        sort(T, T + N);
        total = 0;
        for(i = 0;;)
        {
            head = T[i];
            for(++ i; i < N; ++ i)
                if(T[i] - head > R) break;
            ++ total;
            if(i >= N) break;
            head = T[i - 1];
            for(-- i; i < N; ++ i)
                if(T[i] - head > R) break;
            if(i >= N) break;
        }
        printf("%d\n", total);
    }
    return 0;
}