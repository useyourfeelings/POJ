#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
using namespace std;

int x[26];
int y[26];
char id[26];
char rect[4];

int main()
{
    int i, j, k, n, s = 1;
    while(scanf("%d", &n) && n != 0)
    {
        getchar();
        vector<set<int> > down(n);
        vector<vector<int> > left(n);
        vector<vector<int> > right(n);
        for(i = 0; i < n; ++ i)
        {
            scanf("%c%d%d", &id[i], &x[i], &y[i]);
            getchar();
            for(j = 0; j < i; ++ j)
            {
                if(x[i] == x[j])
                {
                    if(y[i] < y[j]) down[j].insert(i);
                    else down[i].insert(j);
                }
                else if(y[i] == y[j])
                {
                    if(x[i] < x[j])
                    {
                        left[j].push_back(i);
                        right[i].push_back(j);
                    }
                    else
                    {
                        left[i].push_back(j);
                        right[j].push_back(i);
                    }
                }
            }
        }
        vector<string> g;
        set<int>::iterator itr;
        for(i = 0; i < n; ++ i)
        {
            rect[0] = id[i];
            for(j = 0; j < right[i].size(); ++ j)
            {
                rect[1] = id[right[i][j]];
                itr = down[right[i][j]].begin();
                for(; itr != down[right[i][j]].end(); ++ itr)
                {
                    rect[2] = id[*itr];
                    for(k = 0; k < left[*itr].size(); ++ k)
                    {
                        if(down[i].find(left[*itr][k]) != down[i].end())
                        {
                            rect[3] = id[left[*itr][k]];
                            g.push_back(rect);
                        }
                    }
                }
            }
        }
        sort(g.begin(), g.end());
        printf("Point set %d:", s);
        if(g.size() == 0)
        {
            printf(" No rectangles\n");
            ++ s;
            continue;
        }
        printf("\n");
        for(j = 0;;)
        {
            for(i = 0; i < 10 && j < g.size(); ++ i, ++ j)
                cout<<" "<<g[j];
            printf("\n");
            if(j == g.size()) break;
        }
        ++ s;
    }
    return 0;
}