#include<iostream>
using namespace std;

int p[100001];
int d[100001];
int rank[100001];
bool done[100001];

int find(int x)
{
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void link(int x, int y)
{
    if(rank[x] > rank[y]) p[y] = x;
    else p[x] = y;
    if(rank[x] == rank[y]) rank[y] ++;
}

void unify(int x, int y)
{
    link(find(x), find(y));
}

int main()
{   
    int t, n, m, a, b, i;
    char c;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i = 1; i <= n; i++)
        {
            p[i] = i;
            rank[i] = 0;
            done[i] = 0;
            d[i] = -1;
        }
        while(m--)
        {
            cin>>c>>a>>b;
            if(c == 'A')
            {
                if(!done[a] || !done[b])
                {
                    cout<<"Not sure yet."<<endl;
                }
                else
                {
                    if(find(a) == find(b))
                        cout<<"In the same gang."<<endl;
                    else cout<<"In different gangs."<<endl;
                }
            }
            else // 'D'
            {
                if(d[a] == -1 && d[b] == -1)
                {
                    d[a] = b;
                    d[b] = a;
                    done[a] = 1;
                    done[b] = 1;
                    continue;
                }
                if(d[a] != -1 && d[b] == -1)
                {
                    d[b] = a;
                    unify(b, d[a]);
                    done[b] = 1;
                }
                if(d[a] == -1 && d[b] != -1)
                {
                    d[a] = b;
                    unify(a, d[b]);
                    done[a] = 1;
                }
                else
                {
                    unify(a, d[b]);
                    unify(b, d[a]);
                }
            }
        }
    }
    return 0;
}