#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

string move("move");
string onto("onto");
string quit("quit");

void mOnto(vector<list<int> > &home, int a, int b, vector<int> &pos)
{
    list<int>::iterator itr = home[pos[a]].end();
    itr --;
    while(*itr != a)
    {
        home[*itr].push_back(*itr);
        pos[*itr] = *itr;
        itr --;
    }
    home[pos[a]].erase(itr, home[pos[a]].end());
    itr = home[pos[b]].end();
    itr --;
    while(*itr != b)
    {
        home[*itr].push_back(*itr);
        pos[*itr] = *itr;
        itr --;
    }
    home[pos[b]].erase(++itr, home[pos[b]].end());
    home[pos[b]].push_back(a);
    pos[a] = pos[b];
}
void mOver(vector<list<int> > &home, int a, int b, vector<int> &pos)
{
    list<int>::iterator itr = home[pos[a]].end();
    itr --;
    while(*itr != a)
    {
        home[*itr].push_back(*itr);
        pos[*itr] = *itr;
        itr --;
    }
    home[pos[a]].erase(itr, home[pos[a]].end());
    home[pos[b]].push_back(a);
    pos[a] = pos[b];
}
void pOnto(vector<list<int> > &home, int a, int b, vector<int> &pos)
{
    list<int>::iterator itr = home[pos[b]].end();
    itr --;
    while(*itr != b)
    {
        home[*itr].push_back(*itr);
        pos[*itr] = *itr;
        itr --;
    }
    home[pos[b]].erase(++itr, home[pos[b]].end());
    itr = home[pos[a]].end();
    itr --;
    while(*itr != a)
    {
        pos[*itr] = pos[b];
        itr --;
    }
    home[pos[b]].splice(home[pos[b]].end(),
                              home[pos[a]], itr, home[pos[a]].end());
    pos[a] = pos[b];
}
void pOver(vector<list<int> > &home, int a, int b, vector<int> &pos)
{
    list<int>::iterator itr = home[pos[a]].end();
    itr --;
    while(*itr != a)
    {
        pos[*itr] = pos[b];
        itr --;
    }
    home[pos[b]].splice(home[pos[b]].end(),
                              home[pos[a]], itr, home[pos[a]].end());
    pos[a] = pos[b];
}
int main()
{   
    string c1(4, ' ');
    string c2(4, ' ');
    int n, i, a, b;
    cin>>n;
    vector<list<int> > home(n);
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
    {
        home[i].push_back(i);
        pos[i] = i;
    }
    while(cin>>c1 && c1 != quit)
    {
        cin>>a>>c2>>b;
        if(a == b || pos[a] == pos[b]) continue; 
        if(c1 == move)
        {
            if(c2 == onto) mOnto(home, a, b, pos);
            else           mOver(home, a, b, pos);
        }
        else
        {
            if(c2 == onto) pOnto(home, a, b, pos);
            else           pOver(home, a, b, pos);
        }
        for(int i = 0; i < n; i++)
    {
        cout<<i<<":";
        for(list<int>::iterator itr = home[i].begin();
                               itr != home[i].end(); itr++)
            cout<<" "<<*itr;
        cout<<endl;
    }
    }
    for(int i = 0; i < n; i++)
    {
        cout<<i<<":";
        for(list<int>::iterator itr = home[i].begin();
                               itr != home[i].end(); itr++)
            cout<<" "<<*itr;
        cout<<endl;
    }
    return 0;
}
