#include<iostream>
#include<algorithm>
using namespace std;

struct brick
{
    int x;
    int y;
    int z;
};

bool operator<(const brick &a, const brick &b)
{
    return a.x > b.x;
}

brick vb[180];
int hi[180];

int main()
{
    int test = 1, i, n, x, y, z;
    while(scanf("%d", &n) && n != 0)
    {
        n *= 6;
        for(i = 0; i < n ; i += 6)
        {
            scanf("%d%d%d", &x, &y, &z);
            vb[i    ].x = x, vb[i    ].y = y, vb[i    ].z = z;
            vb[i + 1].x = y, vb[i + 1].y = x, vb[i + 1].z = z;
            vb[i + 2].x = x, vb[i + 2].y = z, vb[i + 2].z = y;
            vb[i + 3].x = z, vb[i + 3].y = x, vb[i + 3].z = y;
            vb[i + 4].x = z, vb[i + 4].y = y, vb[i + 4].z = x;
            vb[i + 5].x = y, vb[i + 5].y = z, vb[i + 5].z = x;
        }
        sort(vb, vb + n);
        hi[0] = vb[0].z;
        z = hi[0];
        for(i = 1; i < n; ++ i)
        {
            y = 0;
            for(x = 0; x < i; ++ x)
                if(vb[x].x > vb[i].x && vb[x].y > vb[i].y && hi[x] > y)
                    y = hi[x];
            hi[i] = vb[i].z + y;
            if(hi[i] > z) z = hi[i];
        }
        printf("Case %d: maximum height = %d\n", test ++, z);
    }
    return 0;
}