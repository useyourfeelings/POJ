#include<iostream>
#include<algorithm>
using namespace std;

int pos[100000];
int p, n, i, L, R, mid;

bool OK()
{
    int count = 1, pre = pos[0];
    for(i = 1; i < p; ++ i)
    {
        if(pos[i] >= mid + pre)
        {
            if(++ count == n) return true;
            pre = pos[i];
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &p, &n);
    for(i = 0; i < p; ++ i) scanf("%d", &pos[i]);
    sort(pos, pos + p);
    L = 1;
    R = pos[n - 1] - pos[0];
    for(;;)
    {
        if(L + 1 == R)
        {
            mid = R;
            if(OK) L = R;
            break;
        }
        else
        {
            mid = (L + R) / 2;
            if(OK()) L = mid;
            else     R = mid;
        }
    }
    printf("%d", L);
    return 0;
}