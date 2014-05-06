#include<iostream>
#include<vector>
using namespace std;

vector<int> apple;
vector<int> totalfrom;
int applesize;
int rec[1000][31];

int make(int time, int step)
{
    if(time >= applesize) return 0;
    if(rec[time][step] != -1) return rec[time][step];
    if(step == 0)
    {
        if(time + 1 < applesize) return totalfrom[time + 1];
        return 0;
    }
    int max, t;
    max = apple[time] + make(time + 1, step - 1);// go
    if(time + 1 < applesize)                     // stay
        t = apple[time + 1] + make(time + 2, step);
    else t = 0;
    if(t > max) max = t;
    rec[time][step] = max;
    return max;
}

int main()
{
    int t, w, i, j, count, pre, start;
    scanf("%d%d", &t, &w);
    scanf("%d", &start);
    pre = start;
    count = 1;
    -- t;
    while(t --)
    {
        scanf("%d", &j);
        if(j == pre) ++ count;
        else
        {
            apple.push_back(count);
            count = 1;
            pre = j;
        }
    }
    apple.push_back(count);
    applesize = apple.size();
    totalfrom.resize(applesize);
    for(i = 0; i < applesize; ++ i)
        for(j = 0; j <= w; ++ j)
            rec[i][j] = rec[i][j] = -1;
    
    totalfrom[applesize - 1] = apple[applesize - 1];
    if(applesize > 1) totalfrom[applesize - 2] = apple[applesize - 2];
    for(i = applesize - 3; i >= 0; i -= 2)
        totalfrom[i] = apple[i] + totalfrom[i + 2];
    for(i = applesize - 4; i >= 0; i -= 2)
        totalfrom[i] = apple[i] + totalfrom[i + 2];
    
    if(start == 1) printf("%d", apple.front() + make(1, w));
    else printf("%d", make(0, w));
    return 0;
}