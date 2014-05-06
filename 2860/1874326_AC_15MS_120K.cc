#include<iostream>
using namespace std;

int i, room, step = 0;
int hi[10];
int final;

int main()
{
    scanf("%d%d%d", &i, &i, &room);
    for(i = 0; i < room; ++ i) scanf("%d", &hi[i]);
    for(i = 0; i < room; ++ i)
    {
        scanf("%d", &final);
        if(hi[i] >= final) step += hi[i] - final;
    }
    printf("%d", step);
    return 0;
}
