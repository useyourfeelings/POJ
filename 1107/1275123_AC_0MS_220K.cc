#include<iostream>
#include<vector>
using namespace std;

char s[81];
struct ic
{
    ic(int ii, char cc):id(ii),c(cc){}
    int id;
    char c;
};

int main()
{
    int a, b, c, i, len;
    while(cin>>a>>b>>c && a != 0)
    {
        vector<ic> ga;
        vector<ic> gb;
        vector<ic> gc;
        cin>>s;
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i] > 'r' || s[i] == '_') gc.push_back(ic(i, s[i]));
            else if(s[i] < 'j') ga.push_back(ic(i, s[i]));
            else gb.push_back(ic(i, s[i]));
        }
        len = ga.size();
        for(i = 0; i < len; ++i)
            s[ga[(i + a) % len].id] = ga[i].c;
        len = gb.size();
        for(i = 0; i < len; ++i)
            s[gb[(i + b) % len].id] = gb[i].c;
        len = gc.size();
        for(i = 0; i < len; ++i)
            s[gc[(i + c) % len].id] = gc[i].c;
        cout<<s<<endl;
    }
    return 0;
}