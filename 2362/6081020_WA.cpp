#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int test, N, stick[20], total, len;
char done[20];

FILE *pf = fopen("a.txt", "r");

void input()
{
    total = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++ i)
    {
        scanf("%d", &stick[i]);
        total += stick[i];
        done[i] = 0;
    }
}

bool preprocess()
{
    if(total != (total / 4) * 4)
        return false;
    len = total / 4;
    sort(stick, stick + N, greater<int>());
    if(stick[0] > len)
        return false;
    return true;
}

bool build(int id, int nowlen, int start)
{
    if(nowlen == len) // got one
    {
        if(id == 4)  // all done
        {
            return true;
        }
        int i;
        for (i = 0; i < N; ++ i)
            if(!done[i])
                break;

        done[i] = 1;
        return build(id + 1, stick[i], i + 1);
    }
    if(start >= N)
        return false;
    int t;
    for(int i = start; i < N; ++ i)
    {
        if(done[i]) continue;
        if((t = nowlen + stick[i]) <= len)
        {
            done[i] = 1;            // pick it
            if(build(id, t, i + 1)) // try
                return true;
            done[i] = 0;            // fail, put it back
            t = stick[i];
            ++ i;
            while(i < N && stick[i] == t) // don't pick the same len
                ++ i;
        }
    }
}

bool work()
{
    if(!preprocess())
        return false;
    done[0] = 1;
    return build(1, stick[0], 0);
}

int main()
{
    scanf("%d", &test);
    for(; test > 0; -- test)
    {
        input();
        if(work()) printf("yes\n");
        else       printf("no\n");
    }
    return 0;
}