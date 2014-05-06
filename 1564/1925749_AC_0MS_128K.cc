#include<iostream>
using namespace std;

int total, n, len, i, t, flag;
int num[12], repeat[12], ans[12];

void print()
{
    int i, j;
    for(i = 0; i < len; ++ i)
        if(ans[i] != 0)
        {
            printf("%d", num[i]);
            break;
        }
    for(j = 0; j < ans[i] - 1; ++ j) printf("+%d", num[i]);
    for(++ i; i < len; ++ i)
        if(ans[i] != 0)
        {
            for(j = ans[i]; j > 0; -- j) printf("+%d", num[i]);
        }
    printf("\n");
}

void make(int pos, int re)
{
    if(pos >= len) return;
    int i, j, start, t;
    for(i = min(repeat[pos], re / num[pos]); i >= 0; -- i)
    {
        t = re - i * num[pos];
        ans[pos] = i;
        if(t == 0)
        {
            flag = 1;
            print();
        }
        else make(pos + 1, t);
    }
    ans[pos] = 0;
    return;
}

int main()
{
    while(scanf("%d%d", &total, &n) && total != 0)
    {
        for(i = 0; i < n; ++ i) repeat[i] = 1;
        scanf("%d", &num[0]);
        for(len = i = 1; i < n; ++ i)
        {
            scanf("%d", &t);
            if(t != num[len - 1]) num[len ++] = t;
            else ++ repeat[len - 1];
        }
        printf("Sums of %d:\n", total);
        flag = 0;
        make(0, total);
        if(!flag) printf("NONE\n");
    }
    return 0;
}