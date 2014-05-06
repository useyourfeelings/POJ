#include<iostream>
#include<string>
#include<limits>

using namespace std;

string pat[9] = {"abde", "abc", "bcef", "adg", "bdefh",
                 "cfi", "degh", "ghi", "efhi"};

int clocks[9], move[9], bestmove[9], movePat[9][9];
int minm = INT_MAX, i, j;

void make(int p)
{
    int i, n = 0;
    if(p == 9)
    {
        for(i = 0; i < 9; ++ i)
            if(clocks[i] % 4 != 0) return;
        for(i = 0; i < 9; ++ i) n += move[i];
        if(n < minm)
        {
            minm = n;
            for(i = 0; i < 9; ++ i) bestmove[i] = move[i];
        }
        return;
    }
    for(int repeat = 0; repeat <= 3; ++ repeat)
    {
        for(i = 0; i < p; ++ i) n += move[i];
        n += repeat;
        if(n >= minm) continue;
        for(i = 0; i < 9; ++ i)
            clocks[i] += repeat * movePat[p][i];
        move[p] = repeat;
        make(p + 1);
        for(i = 0; i < 9; ++ i)
            clocks[i] -= repeat * movePat[p][i];
    }
}

int main()
{
    for(i = 0; i < 9; ++ i) cin>>clocks[i];
    for(i = 0; i < 9; ++ i)
        for(j = 0; j < pat[i].size(); ++ j)
            movePat[i][pat[i][j] - 'a'] = 1;
    make(0);
    string blank = "";
    for(i = 0; i < 9; ++ i)
        for(j = 0; j < bestmove[i]; ++ j)
        {
            cout<<blank<<i + 1;
            blank = " ";
        }
    cout<<"\n";
    return 0;
}