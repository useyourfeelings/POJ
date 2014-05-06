#include<iostream>
#include<set>
#include<cmath>
using namespace std;

double graph[200][200];
int stone[200][2];

int main()
{
    set<int>::iterator itr;
    int n, i, j, test = 1, who;
    double fd, min;
    while(scanf("%d", &n) && n != 0)
    {
        fd = -1;
        for(i = 0; i < n; ++ i)
        {
            scanf("%d%d", &stone[i][0], &stone[i][1]);
            for(j = i - 1; j >= 0; -- j)
                graph[i][j] = graph[j][i] = sqrt(
                    (stone[i][0] - stone[j][0]) * (stone[i][0] - stone[j][0]) +
                    (stone[i][1] - stone[j][1]) * (stone[i][1] - stone[j][1]));
        }
        set<int> got;
        got.insert(0);
        for(;;)
        {
            min = 2000;
            for(itr = got.begin(); itr != got.end(); ++ itr) // find the victim
            {
                for(j = 0; j < n; ++ j)
                {
                    if(*itr == j) continue;
                    if(got.find(j) != got.end()) continue;
                    if(graph[*itr][j] < min)
                    {
                        min = graph[*itr][j];
                        who = j;
                    }
                }
            }
            if(min > fd) fd = min;
            if(who == 1) break;
            got.insert(j);
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n", test ++, fd);
    }
    return 0;
}