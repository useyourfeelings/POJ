#include<iostream>
using namespace std;
char man[52];
short state[26];   // 0 : new man    1 : on     2 : gone
int main()
{
    int bn, e, gone;
    while(cin>>bn && bn != 0)
    {
        for(int i = 0; i < 26; i++) state[i] = 0;
        gone = 0;
        cin>>man;
        for(int i = 0; i < strlen(man); i++)
        {
            if(state[man[i] - 65] == 1)  // highing
            {
                bn ++;
                state[man[i] - 65] = 2;
            }
            else if(state[man[i] - 65] == 0) // new
            {
                if(bn > 0)
                {
                    bn --;
                    state[man[i] - 65] = 1;
                }
                else
                {
                    gone ++;
                    state[man[i] - 65] = 2;
                }
            }
        }
        if(gone == 0)
            cout<<"All customers tanned successfully."<<endl;
        else
            cout<<gone<<" customer(s) walked away."<<endl;
    }
    return 0;
}