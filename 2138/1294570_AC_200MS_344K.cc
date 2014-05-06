#include<iostream>
#include<list>
#include<string>
using namespace std;

list<string> d[82];

bool isSub(const string &a, const string &b)
{
    int i, j;
    for(i = 0, j = 0; i < a.size(); ++ i, ++ j)
        if(a[i] != b[j]) break;
    if(i == a.size()) return 1;
    for(++ j; i < a.size(); ++i, ++ j)
        if(a[i] != b[j]) return 0;
    return 1;
}

string make(string x)
{
    int len = x.size(), maxlen;
    string temp, answer(x);
    list<string>::iterator itr = d[len + 1].begin();
    list<string>::iterator end = d[len + 1].end();
    for(maxlen = -1 ; itr != end; ++ itr)
    {
        if(isSub(x, *itr))
        {
            temp = make(*itr);
            if(int(temp.size()) > maxlen)
            {
                maxlen = temp.size();
                answer = temp;
            }
        }
    }
    return answer;
}

int main()
{
    int n, i, j;
    string s, w;
    cin>>n>>s;
    for(i = 0; i < n; ++ i)
    {
        cin>>w;
        d[w.size()].push_back(w);
    }
    cout<<make(s);
    return 0;
}