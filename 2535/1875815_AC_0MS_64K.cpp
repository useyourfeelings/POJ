#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int i, j, n, p, min, max, t;
    scanf("%d%d", &n, &p);
    vector<int> poll(p);
    vector<bool> dead(p, 0);
    for(i = 0; i < n; ++ i)
    {
        vector<int> simple;
        vector<int> hard;
        scanf("%d", &t);
        min = max = t;
        simple.push_back(0);
        hard.push_back(0);
        for(j = 1; j < p; ++ j)
        {
            scanf("%d", &t);
            if(t < min)
            {
                simple.clear();
                simple.push_back(j);
                min = t;
            }
            else if(t == min) simple.push_back(j);
            if(t > max)
            {
                hard.clear();
                hard.push_back(j);
                max = t;
            }
            else if(t == max) hard.push_back(j);
        }
        for(j = 0; j < simple.size(); ++ j)
            if(!dead[simple[j]]) ++ poll[simple[j]];
        for(j = 0; j < hard.size(); ++ j) dead[hard[j]] = true;
    }
    max = 0;
    for(j = 0; j < p; ++ j)
    {
        if(!dead[j] && poll[j] > (n / 2))
        {
            printf("%d ", j + 1);
            ++ max;
        }
    }
    if(max == 0) printf("0");
    return 0;
}