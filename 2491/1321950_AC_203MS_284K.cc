#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int main()
{
    int i, n, j, r;
    char a[31], b[31];
    scanf("%d", &n);
    for(i = 1; i <= n; ++ i)
    {
        map<string, string> route;
        set<string> ss;
        scanf("%d", &r);
        for(j = 1; j < r; ++ j)
        {
            scanf("%s %s", &a, &b);
            set<string>::iterator sitr;
            route.insert(make_pair(a, b));
            if((sitr = ss.find(a)) == ss.end()) ss.insert(a);
            else ss.erase(sitr);
            if((sitr = ss.find(b)) == ss.end()) ss.insert(b);
            else ss.erase(sitr);
        }
        printf("Scenario #%d:\n", i);
        string t;
        if(route.find(*ss.begin()) != route.end()) t = *ss.begin();
        else t = *ss.rbegin();
        cout<<t<<endl;
        for(j = 1; j < r; ++ j)
        {
            t = route.find(t) -> second;
            cout<<t<<endl;
        }
        printf("\n");
    }
    return 0;
}