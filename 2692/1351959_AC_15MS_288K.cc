#include<iostream>
#include<vector>
using namespace std;

char can[20][81];
int vote[1000][20];
bool killed[20];
int get[20];
int now[1000];

int main()
{
    int i, j, n, man = 0, minget, remain;
    bool done = 0;
    vector<int> winner;
    scanf("%d%*c", &n);
    remain = n;
    for(i = 0; i < n; ++ i)
    {
        gets(can[i]);
        killed[i] = 0;
    }
    while(scanf("%d", &vote[man][0]) != EOF)
    {
        now[man] = 0;
        for(j = 1; j < n; ++ j) scanf("%d", &vote[man][j]);
        ++ man;
    }
    for(i = 0;; ++ i)
    {
        memset(get, 0, sizeof(int) * n);
        for(j = 0; j < man; ++ j)
        {
            while(killed[vote[j][now[j]] - 1] && now[j] < n) ++ now[j];
            if(now[j] >= n) continue;
            if(++ get[vote[j][now[j]] - 1] > man / 2)
            {
                winner.push_back(vote[j][now[j]]);
                done = 1;
                break;
            }
        }
        if(done) break;
        vector<int> kill;
        minget = 1001;
        for(j = 0; j < n; ++ j)
        {
            if(!killed[j])
            {
                if(get[j] < minget)
                {
                    kill.clear();
                    kill.push_back(j + 1);
                    minget = get[j];
                }
                else if(get[j] == minget) kill.push_back(j + 1);
            }
        }
        if(remain != kill.size())
        {
            for(j = 0; j < kill.size(); ++ j) killed[kill[j] - 1] = 1;
            remain -= kill.size();
        }
        if(i == n - 1)
        {
            for(j = 0; j < n; ++ j) if(!killed[j]) winner.push_back(j + 1);
            break;
        }
    }
    for(i = 0; i < winner.size(); ++ i) puts(can[winner[i] - 1]);
    return 0;
}
