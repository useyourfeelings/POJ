#include<iostream>
#include<map>
using namespace std;

int main()
{
    char msg[81], temp;
    map<char, char> d;
    int i;
    for(i = 0; i < 26; ++ i)
    {
        cin>>temp;
        d.insert(make_pair(temp, 'a' + i));
        d.insert(make_pair(temp - 32, 'a' + i));
    }
    gets(msg);
    gets(msg);
    for(i = 0; i < strlen(msg); ++ i)
    {
        if(msg[i] == ' ') cout<<" ";
        else cout<<d[msg[i]];
    }
    cout<<endl;
    return 0;
}