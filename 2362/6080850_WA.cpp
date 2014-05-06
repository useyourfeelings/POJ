//poj 2362
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int test, N, stick[20], total, len;
bool result;
char done[20];

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
    return true;
}

void rebuild(int id, int nowlen, int start);

void go(int id)
{
    if(id > 4)
    {
        result = true;
        return;
    }
    int i;
    for (i = 0; i < N; ++ i)
        if(!done[i])
            break;

    done[i] = 1;
    rebuild(id, stick[i], i + 1);
    done[i] = 0;
}

void work()
{
    if(!preprocess())
    {
        result = false;
        return;
    }
    result = false;
    go(1);
}

void rebuild(int id, int nowlen, int start)
{
    if(nowlen == len) // got one
    {
        go(id + 1);   // get next one
        return;
    }
    if(start >= N) return;
    int t;
    for(int i = start; i < N; ++ i)
    {
        if(done[i]) continue;
        if((t = nowlen + stick[i]) <= len)
        {
            done[i] = 1;             // pick it
            rebuild(id, t, i + 1);   // build
            if(result) return;
            done[i] = 0;             // fail, put it back
            t = stick[i];
            ++ i;
            while(i < N && stick[i] == t) // don't pick the same len
                ++ i;
        }
    }
}

int main()
{
    scanf("%d", &test);
    for(; test > 0; -- test)
    {
        input();
        work();
        if(result) printf("yes\n");
        else       printf("no\n");
    }
    return 0;
}