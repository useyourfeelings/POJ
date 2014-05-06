#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{   
    char b1[9];
    char b2[9];
    int n, k, p1, p2;
    bool over = 0;
    
    cin>>n>>k;
    for(;;)
    {
        if(over) break;
        vector<int> win(n + 1, 0);
        vector<int> lose(n + 1, 0);
        vector<int> played(n + 1, 0);
        for(;;)
        {
            cin>>p1;
            if(p1 == 0)
            {
                over = 1;
                break;
            }
            cin>>b1;
            if(isdigit(b1[0]))
            {
                n = p1;
                k = int(b1[0]) - 48;
                break;
            }
            cin>>p2>>b2;
            if(b1[0] == b2[0]) continue;
            if(b1[0] == 'r')
            {
                if(b2[0] == 's')
                {
                    win[p1] ++;
                    lose[p2] ++;
                }
                else
                {
                    win[p2] ++;
                    lose[p1] ++;
                }
                played[p1] ++;
                played[p2] ++;
            }
            else if(b1[0] == 's')
            {
                if(b2[0] == 'p')
                {
                    win[p1] ++;
                    lose[p2] ++;
                }
                else
                {
                    win[p2] ++;
                    lose[p1] ++;
                }
                played[p1] ++;
                played[p2] ++;
            }
            else
            {
                if(b2[0] == 'r')
                {
                    win[p1] ++;
                    lose[p2] ++;
                }
                else
                {
                    win[p2] ++;
                    lose[p1] ++;
                }
                played[p1] ++;
                played[p2] ++;
            }
        }
        for(k = 1; k <= n; k++)
        {
            if((win[k] + lose[k]) != played[k]) cout<<'-'<<endl;
            else
            {
                cout<<setiosflags(ios::fixed)<<setprecision(3)
                    <<double(win[k]) / double((win[k] + lose[k]))<<endl;
            }
        }
        cout<<endl;
    } 
    return 0;
}