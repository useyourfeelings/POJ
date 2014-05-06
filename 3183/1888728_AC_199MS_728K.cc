#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int height[50001];

struct stump
{
    stump(int h, int i):hi(h),id(i){}
    int hi;
    int id;
};

bool pred(const stump &a, const stump &b)
{
    return a.hi > b.hi;
}

int main()
{
    int i, n, j, hi;
    scanf("%d", &n);
    vector<stump> s;
    s.reserve(n);
    for(i = 1; i <= n; ++ i)
    {
        scanf("%d", &height[i]);
        s.push_back(stump(height[i], i));
    }
    sort(s.begin(), s.end(), pred);
    vector<int> bomb;
    for(i = 0; i < n; ++ i)
    {
        if(height[s[i].id] != -1)
        {
            bomb.push_back(s[i].id);
            hi = s[i].hi;
            for(j = s[i].id - 1; j >= 1; -- j)
            {
                if(height[j] == -1) break;
                if(height[j] >= hi) break;
                hi = height[j];
                height[j] = -1;
            }
            hi = s[i].hi;
            for(j = s[i].id + 1; j <= n; ++ j)
            {
                if(height[j] == -1) break;
                if(height[j] >= hi) break;
                hi = height[j];
                height[j] = -1;
            }
        }
    }
    sort(bomb.begin(), bomb.end());
    for(i = 0; i < bomb.size(); ++ i) printf("%d\n", bomb[i]);
    return 0;
}