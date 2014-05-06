#include<iostream>
#include<vector>
#include<set>
#include<list>
using namespace std;

int i, n, p, a, b, ID;

set<int> g;
char node[10001];
int group[10001];
int NumOfGroup[10001];
int in[10001];
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
    set<int>::iterator itr;
    scanf("%d%d", &n, &p);
    for(i = 0; i < p; ++ i)
    {
        scanf("%d%d", &a, &b);
        g.insert(a * 100000 + b);
    }
    GetFinishOrder();
    GetGroup();
    vector<set<int> > gg(ID);
    vector<int> support(ID);
    for(a = 1; a < ID; ++ a)
    {
        in[a] = 0;
        support[a] = NumOfGroup[a];
    }
    for(a = 1; a < n; ++ a)
        for(b = a + 1; b <= n; ++ b)
        {
            if(group[a] != group[b])
            {
                if(g.find(a * 100000 + b) != g.end())
                {
                    if(gg[group[a]].find(group[b]) == gg[group[a]].end())
                    {
                        ++ in[group[b]];
                        gg[group[a]].insert(group[b]);
                    }
                }
                else if(g.find(b * 100000 + a) != g.end())
                {
                    if(gg[group[b]].find(group[a]) == gg[group[b]].end())
                    {
                        gg[group[b]].insert(group[a]);
                        ++ in[group[a]];
                    }
                }
            }
        }
    p = -1;
    int BestGroup;
    list<int> todo;
    list<int>::iterator listitr;
    for(b = 1; b < ID; ++ b) if(in[b] == 0) todo.push_back(b);
    while(!todo.empty())
    {
        i = todo.size();
        for(listitr = todo.begin(); i >= 0; -- i, ++ listitr)
        {
            if(support[*listitr] > p)
            {
                p = support[*listitr];
                BestGroup = *listitr;
            }
            for(itr = gg[*listitr].begin(); itr != gg[*listitr].end(); ++ itr)
            {
                if(-- in[*itr] == 0) todo.push_back(*itr);
                support[*itr] += support[*listitr];
            }
        }
        todo.erase(todo.begin(), listitr);
    }
    printf("%d", NumOfGroup[BestGroup]);
    return 0;
}