#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

int main()
{   
    char u[20], v[40];
    double a, r;
    int p;
    vector<string> vs;
    while(scanf("%lf", &a) && int(a) != -1)
    {
        scanf("%s%lf ", &u, &r);
        gets(v);
        if((p = int(100 * a / r)) < 1)
        {
            vs.push_back(string(v));
            continue;
        }
        cout<<v<<" "<<setiosflags(ios::fixed)<<setprecision(1)
            <<a<<" "<<u<<" "<<p<<"%"<<endl;
    }
    cout<<"Provides no significant amount of:"<<endl;
    vector<string>::iterator itr = vs.begin();
    vector<string>::iterator end = vs.end();
    for(; itr != end; ++ itr) cout<<*itr<<endl;
    return 0;
}