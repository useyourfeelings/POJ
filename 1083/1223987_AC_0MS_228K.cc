#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
struct sd
{
    sd(short ss, short dd):s(ss),d(dd){}
    short s;
    short d;
};
struct pri
{
    bool operator()(const sd &a, const sd &b) const {return a.s < b.s;}
};
int main()
{   
    int t, n, ss, dd, i, flag;
    cin>>t;
    while(t--)
    {
        cin>>n;
        list<sd> lsd;
        while(n--)
        {
            cin>>ss>>dd;
            if(ss <= dd) lsd.push_back(sd(ss, dd));
            else         lsd.push_back(sd(dd, ss)); 
        }
        lsd.sort(pri());
        i = 0;
        while(!lsd.empty())
        {
            list<sd>::iterator itr = lsd.begin();
            flag = 0;
            while(itr != lsd.end())
            {
                if(flag % 2 == 0)
                {
                    if((itr -> s) > flag)
                    {
                        flag = itr -> d;
                        itr = lsd.erase(itr);
                    }
                    else ++itr;
                }
                else
                {
                    if((itr -> s) > flag + 1)
                    {
                        flag = itr -> d;
                        itr = lsd.erase(itr);
                    }
                    else ++itr;
                }
            }
            ++i;
        }
        cout<<i * 10<<endl;
    }
    return 0;
}