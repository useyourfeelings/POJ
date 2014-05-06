#include<iostream>
using namespace std;

char a[50000];
int size;

int make(int id)
{
    if(id < 0) return 1;
    int count = 0;
    
    if(a[id] == '0') count = make(id - 2);
    else if(a[id] > '6')
    {
        if(id == 0)               count = 1;
        else if(a[id - 1] == '1') count = make(id - 1) + make(id - 2);
        else                      count = make(id - 1);
    }
    else // 1 ~ 6
    {
        if(id == 0) count = 1;
        else if(a[id - 1] == '1' || a[id - 1] == '2')
            count = make(id - 1) + make(id - 2);
        else count = make(id - 1);
    }
    return count;
}

int main()
{   
    while(cin>>a && a[0] != '0')
    {
        size = strlen(a);
        cout<<make(size - 1)<<endl;
    }
    return 0;
}