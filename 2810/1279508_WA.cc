#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{   
    char bad;
    string u, v;
    double a, r, p;
    vector<string> vs;
    while(cin>>a && int(a) != -1)
    {
        cin>>u>>r;
        scanf("%*c");
        getline(cin, v);
        if((p = 100 * a / r) < 1)
        {
            vs.push_back(string(v));
            continue;
        }
        cout<<v<<" "<<setiosflags(ios::fixed)<<setprecision(1)
            <<a<<" "<<u<<" "<<int(p)<<"%"<<endl;
    }
    cout<<"Provides no significant amount of:"<<endl;
    vector<string>::iterator itr = vs.begin();
    vector<string>::iterator end = vs.end();
    for(; itr != end; ++ itr) cout<<*itr<<endl;
    return 0;
}