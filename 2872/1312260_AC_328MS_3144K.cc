#include<iostream>
#include<set>
#include<vector>
#include<string>
using namespace std;

char t[40];
string eof("-1");

int main()
{
    int n, i, j;
    set<string> dic;
    scanf("%d", &n);
    for(i = 0; i < n; ++ i)
    {
        scanf("%s", &t);
        dic.insert(t);
    }
    scanf("%d", &n);
    for(i = 1; i <= n; ++ i)
    {
        vector<string> un;
        while(scanf("%s", &t) && string(t) != eof)
            if(dic.find(t) == dic.end()) un.push_back(t);
        if(un.empty()) printf("Email %d is spelled correctly.\n", i);
        else
        {
            printf("Email %d is not spelled correctly.\n", i);
            for(j = 0; j < un.size(); ++ j) cout<<un[j]<<endl;
        }
    }
    printf("End of Output\n");
    return 0;
}
