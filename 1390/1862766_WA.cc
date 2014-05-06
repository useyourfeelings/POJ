#include<iostream>
#include<vector>
using namespace std;

vector<int> color, num;
int record[201][201][201];

int make(int i, int j, int len)
{
    if(record[i][j][len] != -1) return record[i][j][len];
    int t;
    if(i == j)
    {
        t = (num[i] + len) * (num[i] + len);
        record[i][j][len] = t;
        return t;
    }
    int p;
    for(p = j - 2; p >= 0; -- p)
    {
        if(color[p] == color[j]) break;
    }
    if(p < 0)
    {
        t = make(i, j - 1, 0) + (num[j] + len) * (num[j] + len);
        record[i][j][len] = t;
        return t;
    }
    else
    {
        t = max(make(i, j - 1, 0) + (num[j] + len) * (num[j] + len),
                    make(p + 1, j - 1, 0) + make(i, p, num[j] + len));
        record[i][j][len] = t;
        return t;
    }       
}

int main()
{
    int test, t, i, n, temp, j;
    scanf("%d", &test);
    for(t = 1; t <= test; ++ t)
    {
        color.clear();
        num.clear();
        scanf("%d", &n);
        for(i = 0; i < n; ++ i)
            for(j = 0; j < n; ++ j)
                for(temp = 0; temp < n; ++ temp) record[i][j][temp] = -1;
        for(i = 0; i < n; ++ i)
        {
            scanf("%d", &temp);
            if(color.empty() || color.back() != temp)
            {
                color.push_back(temp);
                num.push_back(1);
            }
            else
            {
                ++ num[num.size() - 1];
            }
        }
        printf("Case %d: %d\n", t, make(0, color.size() - 1, 0));
    }
    return 0;
}