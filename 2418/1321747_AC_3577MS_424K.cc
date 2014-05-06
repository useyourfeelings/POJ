#include<iostream>
#include<map>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
    cout<<setprecision(4)<<setiosflags(ios::fixed);
    char t[31];
    int total = 0;
    map<string, double> m;
    map<string, double>::iterator itr;
    while(gets(t))
    {
        total ++;
        if((itr = m.find(t)) != m.end()) ++ itr -> second;
        else m.insert(make_pair(t, 1));
    }
    map<string, double>::iterator end = m.end();
    for(itr = m.begin(); itr != end; ++itr)
    {
        cout<<itr -> first<<" "<<itr -> second * 100 / total<<endl;
    }
    return 0;
}