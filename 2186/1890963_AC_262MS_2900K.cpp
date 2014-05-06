#include<iostream>
#include<vector>
#include<list>
using namespace std;

int i, n, p, a, b, ID;

vector<list<int> > g;
vector<list<int> > gt;
char node[10001];
int group[10001];
int NumOfGroup[10001];
vector<int> finish;

list<int>::iterator listitr;

void dfs_1(int u)
{
    node[u] = 1;
    for(list<int>::iterator listitr = g[u].begin();
        listitr != g[u].end(); ++ listitr)
        if(node[*listitr] == 0) dfs_1(*listitr);
    finish.push_back(u);
}

void GetFinishOrder()
{
    int i;    for(i = 1; i <= n; ++ i) node[i] = 0;
    for(i = 1; i <= n; ++ i) if(node[i] == 0) dfs_1(i);
}

void dfs_2(int u)
{
    group[u] = ID;
    ++ NumOfGroup[ID];
    for(list<int>::iterator listitr = gt[u].begin();
        listitr != gt[u].end(); ++ listitr)
        if(group[*listitr] == 0) dfs_2(*listitr);
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
    g.resize(n + 1);
    gt.resize(n + 1);
    for(i = 0; i < p; ++ i)
    {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        gt[b].push_back(a);
    }
    GetFinishOrder();
    GetGroup();
    for(a = 1; a < ID; ++ a) finish[a] = 0;
    for(a = 1; a <= n; ++ a)
    {
        if(finish[group[a]] == 1) continue;
        for(listitr = g[a].begin(); listitr != g[a].end(); ++ listitr)
            if(group[a] != group[*listitr]) break;
        if(listitr != g[a].end())  finish[group[a]] = 1;
    }
    b = 0;
    for(a = 1; a < ID; ++ a)
    {
        if(finish[a] == 0)
        {
            if(b != 0)
            {
                b = 0;
                break;
            }
            b = NumOfGroup[a];
        }
    }
    printf("%d", b);
    return 0;
}