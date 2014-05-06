#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{   
    int i;
    char bad, v[30];
    string u;
    double a, r, p;
    vector<string> vs;
    while(cin>>a && int(a) >= 0)
    {
        cin>>u>>r;
        getchar();
        gets(v);
        for(i = strlen(v) - 1; i >= 0; -- i)
        {
            if(v[i] == ' ') v[i] = 0;
            else break;
        }
        if((p = 100 * a / r) < 1)
        {
            vs.push_back(v);
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