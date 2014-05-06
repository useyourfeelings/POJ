#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{   
    string id;
    while(cin>>id && id[0] != '#')
    {
        if(next_permutation(id.begin(), id.end()))
            cout<<id<<endl;
        else cout<<"No Successor"<<endl;
    }
    return 0;
}