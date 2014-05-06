#include<iostream>
using namespace std;

char a[5000];
int size;
int b[5000];

int make(int id)
{
    if(id < 0) return 1;
    if(b[id] != -1) return b[id];
    int count = 0;
    
    if(a[id] == '0') count = make(id - 2);
    else if(a[id] > '6')
    {
        if(a[id - 1] == '1') count = make(id - 1) + make(id - 2);
        else                 count = make(id - 1);
    }
    else // 1 ~ 6
    {
        if(a[id - 1] == '1' || a[id - 1] == '2')
            count = make(id - 1) + make(id - 2);
        else count = make(id - 1);
    }
    b[id] = count;
    return count;
}

int main()
{   
    while(cin>>a && a[0] != '0')
    {
        size = strlen(a);
        for(int i = 1; i < size; i++) b[i] = -1;
        b[0] = 1;
        make(size - 1);
        cout<<b[size - 1]<<endl;
    }
    return 0;
}