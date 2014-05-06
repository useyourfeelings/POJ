#include<iostream>
using namespace std;

char buffer[32];
char winner[32];

int main()
{
    int n, i, j, solved = 0, penalty = 0, s, p, a, b;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%s", buffer);
        s = p = 0;
        for(j = 0; j < 4; ++ j)
        {
            scanf("%d%d", &a, &b);
            if(b == 0) continue;
            ++ s;
            p += (b + (a - 1) * 20);
        }
        if(s > solved)
        {
            strcpy(winner, buffer);
            solved = s;
            penalty = p;
        }
        else if(s == solved)
        {
            if(p < penalty)
            {
                strcpy(winner, buffer);
                penalty = p;
            }
        }
    }
    printf("%s %d %d", winner, solved, penalty);
    return 0;
}