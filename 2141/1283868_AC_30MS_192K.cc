#include<iostream>
using namespace std;
int main()
{
    char msg[81], d[27];
    gets(d);
    gets(msg);
    for(int i = 0; i < strlen(msg); ++ i)
    {
        if(msg[i] == ' ') cout<<" ";
        else if(int(msg[i]) >= 97) cout<<d[int(msg[i] - 97)];
        else cout<<char(d[int(msg[i] - 65)] - 32);
    }
    cout<<endl;
    return 0;
}