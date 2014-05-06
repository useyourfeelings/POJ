#include<iostream>
#include<vector>
#include<set>
using namespace std;

int i, n, p, a, b, ID;

set<int> g;
char node[10001];
int group[10001];
int NumOfGroup[10001];
char out[10001];
vector<int> finish;

void dfs_1(int u)
{
    node[u] = 1;
    for(int i = 1; i <= n; ++ i)
        if(g.find(u * 100000 + i) != g.end() && node[i] == 0) dfs_1(i);
    finish.push_back(u);
}

void GetFinishOrder()
{
    int i;
    for(i = 1; i <= n; ++ i) node[i] = 0;
    for(i = 1; i <= n; ++ i) if(node[i] == 0) dfs_1(i);
}

void dfs_2(int u)
{
    group[u] = ID;
    ++ NumOfGroup[ID];
    for(int i = 1; i <= n; ++ i)
        if(g.find(i * 100000 + u) != g.end() && group[i] == 0) dfs_2(i);
}

void GetGroup()
{
    int i;
    ID = 1;
    for(i = 1; i <= n; ++ i) group[i] = 0;
    for(i = finish.size() - 1; i >= 0; -- i)
        if(group[finish[i]] == 0)
        {
            NumOfGroup[ID] = 0;
            dfs_2(finish[i]);
            ++ ID;
        }
}

int main()
{
    scanf("%d%d", &n, &p);
    for(i = 0; i < p; ++ i)
    {
        scanf("%d%d", &a, &b);
        g.insert(a * 100000 + b);
    }
    GetFinishOrder();
    GetGroup();
    for(a = 1; a < ID; ++ a) out[a] = 0;
    for(a = 1; a < n; ++ a)
        for(b = a + 1; b <= n; ++ b)
        {
            if(group[a] != group[b])
            {
                if(g.find(a * 100000 + b) != g.end()) out[group[a]] = 1;
                else if(g.find(b * 100000 + a) != g.end()) out[group[b]] = 1;
            }
        }
    a = 0;
    for(b = 1; b < ID; ++ b)
    {
        if(out[b] == 0)
        {
            if(a != 0)
            {
                a = 0;
                break;
            }
            else a = NumOfGroup[b];
        }
    }
    printf("%d", a);
    return 0;
}