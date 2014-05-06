#include<iostream>
#include<algorithm>
using namespace std;

struct Doll
{
    int w;
    int h;
};

bool operator<(const Doll &a, const Doll &b)
{
    if(a.w == b.w) return a.h < b.h;
    return a.w < b.w;
}

Doll doll[20000];
int isOld[20000];

int test, num, i, end;

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d", &num);
        for(i = 0; i < num; ++ i)
            scanf("%d%d", &doll[i].w, &doll[i].h);
        sort(doll, doll + num);
        memset(isOld, 0, num * sizeof(int));
        isOld[num - 1] = 1;
        end = num - 1;
        num = 1;
        while(end >= 0)
        {
            if(!isOld[end]) ++ num;
            for(i = end - 1; i >= 0; -- i)
                if(doll[i].w < doll[end].w && doll[i].h < doll[end].h)
                {
                    isOld[i] = 1;
                    
                    break;
                }
            -- end;
        }
        printf("%d\n", num);
    }
    return 0;
}