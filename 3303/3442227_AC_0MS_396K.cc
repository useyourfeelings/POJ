#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Event
{
    Event(int q, int t, int o):quest(q),time(t),op(o){}
    int quest;
    int time;
    int op;
};

bool operator<(const Event &a, const Event &b)
{
    if(a.time == b.time) return a.op < b.op;
    return a.time < b.time;
}

const int CHECK_IN = 1, CHECK_OUT = 2;
int test, quest, quest2;
int cand[12][9];
char good[24][256];
int use[12];// whitch quest use which hall

vector<Event> event;

int dp(int pos, unsigned int state)  // 1 - free    0 - in use
{
    if(pos >= quest2) return 1;
    if(good[pos][state] != 2) return good[pos][state];
    int who = event[pos].quest;
    unsigned int mask;
    if(event[pos].op == CHECK_OUT)
    {
        mask = 1 << (use[who] - 1);
        return dp(pos + 1, state | mask);
    }
    else
    {
        for(int i = cand[who][0]; i >= 1; -- i)
        {
            mask = 1 << (cand[who][i] - 1);
            if((state & mask) == 0) continue;   //   in use
            use[who] = cand[who][i];
            if(dp(pos + 1, state & (~ mask)))
            {
                good[pos][state] = 1;
                return 1;
            }
        }
        good[pos][state] = 0;
        return 0;
    }
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        event.clear();
        scanf("%d", &quest);
        quest2 = 2 * quest;
        int t1, t2, num, can;
        for(int i = 0; i < quest; ++ i)
        {
            scanf("%d%d%d", &t1, &t2, &num);
            cand[i][0] = num;
            event.push_back(Event(i, t1, CHECK_IN));
            event.push_back(Event(i, t2, CHECK_OUT));
            for(int j = 1; j <= num; ++ j)
                scanf("%d", &cand[i][j]);
        }
        sort(event.begin(), event.end());
        for(int i = 0; i < quest2; ++ i)
            for(int j = 0; j < 256; ++ j)
                good[i][j] = 2;
        if(dp(0, 255)) printf("YES\n");
        else           printf("NO\n");
    }
    return 0;
}
