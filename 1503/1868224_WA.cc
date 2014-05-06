#include<iostream>
#include<vector>
using namespace std;

char digits[105][105];
int index[105];

int main()
{
    int i, LineNo = 0, DoneNo, sum, pre;
    while(cin>>digits[LineNo])
    {
        index[LineNo] = strlen(digits[LineNo]) - 1;
        ++ LineNo;
    }
    -- LineNo;
    DoneNo = pre = 0;
    vector<char> g;
    while(DoneNo != LineNo)
    {
        sum = 0;
        for(i = 0; i < LineNo; ++ i)
        {
            if(index[i] >= 0)
            {
                sum += int(digits[i][index[i]]) - 48;
                -- index[i];
                if(index[i] < 0) ++ DoneNo;
            }
        }
        sum += pre;
        pre = sum / 10;
        g.push_back(char(sum % 10 + 48));
    }
    i = g.size() - 1;
    while(g[i] == '0') -- i;
    for(; i >= 0; -- i) cout<<g[i];
    return 0;
}