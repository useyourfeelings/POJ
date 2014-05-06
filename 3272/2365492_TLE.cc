#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> into(5001, 0), toend(5001, 0); // size of points to the point
vector<vector<int> > from(5001), to(5001);
vector<int> total(5001, 0);
set<int> can;

int main()
{
    int N, M, i, a, b, who, t, answer = 0;
    scanf("%d%d", &N, &M);
    for(i = 0; i < M; ++ i)
    {
        scanf("%d%d", &a, &b);
        from[a].push_back(b);
        to[b].push_back(a);
        ++ into[b];
    }
    for(i = 1; i < N; ++ i)
        if(into[i] == 0)
        {
            total[i] = 1;
            can.insert(i);
        }
    while(!can.empty())
    {
        who = *can.begin();
        can.erase(can.begin());
        for(i = from[who].size() - 1; i >= 0; -- i)
        {
            t = from[who][i];
            total[t] += total[who];
            if(-- into[t] == 0)
                can.insert(t);
        }
    }
    can.insert(N);
    while(!can.empty())
    {
        who = *can.begin();
        can.erase(can.begin());
        toend[who] = 1;
        can.insert(to[who].begin(), to[who].end());
    }
    for(i = 1; i < N; ++ i)
        if(toend[i] == 1 && total[i] > answer) answer = total[i];
    printf("%d", answer);
    system("pause");
    return 0;
}