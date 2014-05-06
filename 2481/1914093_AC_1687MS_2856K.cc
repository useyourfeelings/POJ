#include<iostream>
#include<algorithm>
using namespace std;

int n, i, j, tail, who, head;

struct segment
{
    int a;
    int b;
    int id;
};

bool operator<(const segment &x, const segment &y)
{
    if(x.b == y.b) return x.a < y.a;
    return x.b > y.b;
}

segment line[100000];
int strong[100000];
int tree[300001];

void build()
{
    memset(tree, 0, sizeof(int) * tail * 3);
}

int CountPoint()
{
    int i = head, j = tail, pos = 0, mid, ret = 0;
    for(;;)
    {
        mid = (i + j) / 2;
        if(who == mid)
        {
            ret += tree[pos];
            break;
        }
        else if(who < mid)
        {
            j = mid;
            pos = pos * 2 + 1;
        }
        else
        {
            ret += tree[pos];
            i = mid + 1;
            pos = pos * 2 + 2;
        }
    }
    return ret;
}

void insert()
{
    int i = head, j = tail, mid, pos = 0;
    for(;;)
    {
        mid = (i + j) / 2;
        if(who == mid)
        {
            ++ tree[pos];
            break;
        }
        else if(who < mid)
        {
            ++ tree[pos];
            j = mid;
            pos = pos * 2 + 1;
        }
        else
        {
            i = mid + 1;
            pos = pos * 2 + 2;
        }
    }
}

int main()
{
    while(scanf("%d", &n) && n != 0)
    {
        head = 10000000;
        for(i = 0; i < n; ++ i)
        {
            scanf("%d%d", &line[i].a, &line[i].b);
            if(line[i].a < head) head = line[i].a;
            line[i].id = i;
        }
        sort(line, line + n);
        tail = line[0].b;
        build();
        who = line[0].a;
        insert();
        strong[line[0].id] = 0;
        for(i = 1; i < n; ++ i)
        {
            who = line[i].a;
            strong[line[i].id] = CountPoint();
            for(j = i - 1; j >= 0; -- j)
            {
                if(line[j].a == line[i].a && line[j].b == line[i].b)
                    -- strong[line[i].id];
                else break;
            }
            insert();
        }
        for(i = 0; i < n; ++ i) printf("%d ", strong[i]);
        printf("\n");
    }
    return 0;
}