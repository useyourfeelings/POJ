#include<iostream>
using namespace std;
const int N = 10;
char a[N];
int main()
{
    int sum = 0, index = -1;
    cin>>a;
    for(int i = 0; i < N - 1; i++)
    {
        if(a[i] == '?')
        {
            index = i;
            continue;
        }
        sum += (int(a[i]) - 48) * (N - i);
    }
    if     (a[N - 1] == 'X') sum += 10;
    else if(a[N - 1] == '?') index = N - 1;
    else sum += (int(a[N - 1]) - 48);
    
    for(int i = 0; i < 11; i++)
    {
        if((sum + i * (N - index)) % 11 == 0)
        {
            if(index != N - 1 && i != 10)
            {
                cout<<i<<endl;
                break;
            }
            else if(index == N - 1)
            {
                if(i != 10) cout<<i<<endl;
                else cout<<'X'<<endl;
                break;
            }
        }
        if(i == 10) cout<<-1;
    }
    return 0;
}