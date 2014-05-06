#include<iostream>
#include<vector>
using namespace std;

vector<int> into(5001, 0), toend(5001, 0);
vector<vector<int> > from(5001), to(5001);
vector<int> total(5001, 0), done(5001, 0), queue(5001);

int main()
{
    int N, M, i, a, b, who, t, answer = 0, head, end;
    scanf("%d%d", &N, &M);
    for(i = 0; i < M; ++ i)
    {
        scanf("%d%d", &a, &b);
        from[a].push_back(b);
        to[b].push_back(a);
        ++ into[b];
    }
    head = end = 0;
    for(i = 1; i < N; ++ i)
        if(into[i] == 0) 
        {
            total[i] = 1;
            done[i] = 1;
            queue[end ++] = i;
        }
    while(head < end)
    {
        who = queue[head ++];
        for(i = from[who].size() - 1; i >= 0; -- i)
        {
            t = from[who][i];
            total[t] += total[who];
            if(-- into[t] == 0 && !done[t])
            {
                queue[end ++] = t;
                done[t] = 1;
            }
        }
    }
    for(i = 1; i <= N; ++ i) done[i] = 0;
    queue[0] = N;
    head = 0;
    end = 1;
    while(head < end)
    {
        who = queue[head ++];
        toend[who] = 1;
        done[who] = 1;
        for(i = to[who].size() - 1; i >= 0; -- i)
            if(!done[to[who][i]])
            {
                queue[end ++] = to[who][i];
                done[to[who][i]] = 1;
            }
    }
    for(i = 1; i <= N; ++ i)
        if(toend[i] == 1)
        {
            for(a = to[i].size() - 1; a >= 0; -- a)
                if(total[to[i][a]] > answer) answer = total[to[i][a]];
        }
    printf("%d", answer);
    return 0;
}