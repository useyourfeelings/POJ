#include<iostream>
using namespace std;
short p[26][26];
bool done[26];
int main()
{   
    short vNo, num, i, j, weight, lastj, sum;
    char v, va;
    while(cin>>vNo && vNo != 0)
    {
        for(i = 0; i < vNo; i ++)
        {
            done[i] = 0;
            for(j = 0; j < vNo; j ++) p[i][j] = 0;
        }
        for(i = 0; i < vNo - 1; i ++)
        {
            cin>>v>>num;
            for(j = 0; j < num; j ++)
            {
                cin>>va>>weight;
                if(short(va) - 65 == num - 1)
                {
                    p[num - 1][short(v) - 65] = weight;
                    p[short(v) - 65][num - 1] = weight;
                }
                p[short(v) - 65][short(va) - 65] = weight;
                p[short(va) - 65][short(v) - 65] = weight;
            }
        }
        num = 1;
        done[0] = 1;
        sum = 0;
        for(;;)
        {
            weight = 101;
            for(i = 0; i < vNo; i ++)
            {
                if(done[i])
                {
                    for(j = 0; j < vNo; j++)
                    {
                        if(p[j][i] == 0  ||  done[j]) continue;
                        if(p[i][j] < weight)
                        {
                            weight = p[i][j];
                            lastj = j;
                        }
                    }
                } 
            }
            sum += weight;
            done[lastj] = 1;
            num ++;
            if(num == vNo) break;
        }
        cout<<sum<<endl;
    }
    return 0;
}