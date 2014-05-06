#include<iostream>
using namespace std;
int infinity = 600000000;
int w[512];
int p[512];
int record[10240];
int main()
{   
    int Case, e, f, num;
    cin>>Case;
    while(Case--)
    {
        cin>>e>>f>>num;
        f -= e;
        for(e = 0; e < num; e++) cin>>p[e]>>w[e];
        record[0] = 0;
        for(e = 1; e <= f; e++)
        {
            record[e] = infinity;
            for(int i = 0; i < num; i++)
            {
                if(w[i] <= e)
                    if(record[e - w[i]] + p[i] < record[e])
                        record[e] = record[e - w[i]] + p[i];
            }
        }
        if(record[f] < infinity)
            cout<<"The minimum amount of money in the piggy-bank is "
                <<record[f]<<endl;
        else
            cout<<"This is impossible."<<endl;
    }     
    return 0;
}
