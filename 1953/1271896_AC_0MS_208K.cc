#include<iostream>
using namespace std;

int size;
int b[45][2];

int make(int id, int pre)
{
    if(b[id][pre] != -1) return b[id][pre];
    if(id == 0)
    {
        if(pre == 1)
        {
            b[id][1] = 1;
            return 1;
        }
        else
        {
            b[id][0] = 2;
            return 2;
        }
    }
    int count;
    if(pre == 1) count = make(id - 1, 0);
    else         count = make(id - 1, 0) + make(id - 1, 1);
    b[id][pre] = count;
    return count;
}

int main()
{   
    int t, i;
    cin>>t;
    for(i = 1; i <= t; i++)
    {
        cin>>size;
        for(int i = 0; i < size; i++) b[i][0] = b[i][1] = -1;
        if(size == 1) cout<<"Scenario #"<<i<<":"<<endl<<"2"<<endl<<endl;
        else cout<<"Scenario #"<<i<<":"<<endl
                 <<make(size - 2, 1) + make(size - 2, 0)<<endl<<endl;
    }
    return 0;
}