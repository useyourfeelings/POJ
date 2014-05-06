#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int test, N, stick[20], total, len;
char picked[20];

void input()
{
    total = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; ++ i)
    {
        scanf("%d", &stick[i]);
        total += stick[i];
        picked[i] = 0;
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
            if(!picked[i])
                break;
        picked[i] = 1;
        if(build(id + 1, stick[i], i + 1))
            return true;
        picked[i] = 0;
        return false;
    }
    if(start >= N)
        return false;
    int t;
    for(int i = start; i < N; ++ i)
    {
        if(picked[i]) continue;
        if((t = nowlen + stick[i]) <= len)
        {
            picked[i] = 1;            // pick it
            if(build(id, t, i + 1)) // try
                return true;
            picked[i] = 0;            // fail, put it back
            t = stick[i];
            ++ i;
            while(i < N && stick[i] == t) // don't pick the same len
                ++ i;
            -- i;
        }
    }
    return false;
}

bool work()
{
    if(!preprocess())
        return false;
    picked[0] = 1;
    return build(1, stick[0], 1);
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