#include<iostream>
#include<functional>
#include<limits>
#include<map>
using namespace std;

int main()
{   
    int n, x, y, count;
    while(cin>>n && n != 0)
    {
        map<int, int, greater<int> > iim;
        while(n --)
        {
            cin>>x>>y;
            map<int, int>::iterator itr;
            if((itr = iim.find(x)) != iim.end())
            {
                if(itr -> second < y) itr -> second = y;
            }
            else
            {
                iim.insert(make_pair(x, y));
            }
        }
        map<int, int>::iterator itr = iim.begin();
        map<int, int>::iterator end = iim.end();
        n = INT_MIN;
        count = 0;
        for(; itr != end; ++itr)
        {
            if(itr -> second > n)
            {
                count ++;
                n = itr -> second;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}