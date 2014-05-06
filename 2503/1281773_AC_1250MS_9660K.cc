#include<iostream>
#include<string>
#include<map>
using namespace std;

char t[25];
char f[12];
char e[12];

int main()
{
    map<string, string> d;
    int i, j;
    while(gets(t) && strlen(t) != 0)
    {
        for(i = 0; ; i++)
        {
            if(t[i] == ' ') break;
            e[i] = t[i];
        }
        for(++i, j = 0; i < strlen(t); ++ i, ++ j) f[j] = t[i];
        d.insert(make_pair(string(f), string(e)));
    }
    while(scanf("%s", f) != EOF)
    {
        map<string, string>::iterator itr;
        if((itr = d.find(string(f))) != d.end())
            cout<<itr -> second<<endl;
        else printf("eh\n");
    }
    return 0;
}