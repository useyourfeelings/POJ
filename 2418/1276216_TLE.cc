#include<iostream>
#include<map>
#include<iomanip>
#include<cstring>
using namespace std;

int main()
{   
    char t[31];
    int total = 0;
    map<string, double> m;
    map<string, double>::iterator itr;
    while(cin.getline(t, 31, '\n'))
    {
        total ++;
        if((itr = m.find(string(t))) != m.end()) itr -> second += 1;
        else m.insert(make_pair(string(t), 1));
    }
    map<string, double>::iterator end = m.end();
    for(itr = m.begin(); itr != end; ++itr)
    {
        cout<<itr -> first<<" "<<setprecision(4)<<setiosflags(ios::fixed)
            <<itr -> second * 100 / total<<endl;
    }
    return 0;
}