#include<iostream>
using namespace std;

char nodes[26][2];
char in[27][27];
char head;

void insert(int who)
{
    char now = head;
    for(;;)
    {
        if(who < now)
        {
            if(nodes[now - 65][0] == 0)
            {
                nodes[now - 65][0] = who;
                break;
            }
            else now = nodes[now - 65][0];
        }
        else
        {
            if(nodes[now - 65][1] == 0)
            {
                nodes[now - 65][1] = who;
                break;
            }
            else now = nodes[now - 65][1];
        }
    }
}

void print(char now)
{
    if(now == 0) return;
    printf("%c", now);
    print(nodes[now - 65][0]);
    print(nodes[now - 65][1]);
}

int main()
{
    int n, i, j;
    while(scanf("%s", in[0]))
    {
        memset(nodes, 0, sizeof(nodes));
        for(n = 1;;)
        {
            scanf("%s", in[n]);
            if(in[n][0] == '*' || in[n][0] == '$') break;
            ++ n;
        }
        head = in[n - 1][0];
        for(j = n - 2; j >= 0; -- j)
            for(i = 0; i < strlen(in[j]); ++ i)
                insert(in[j][i]);
        print(head);
        if(in[n][0] == '$') break;
        printf("\n");
    }
    return 0;
}