#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

char key[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5',
        '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
char buff[128];
char code[128];

int main()
{
    int s, scenario, word, input, pro, i, len;
    map<string , map<int, set<string> > >::iterator itr1;
    map<int, set<string> >::iterator itr2;
    set<string>::iterator itr3;
    scanf("%d", &s);
    for(scenario = 1; scenario <= s; ++ scenario)
    {
        printf("Scenario #%d:\n", scenario);
        map<string , map<int, set<string> > > dic;
        scanf("%d", &word);
        while(word --)
        {
            scanf("%s %d", &buff, &pro);
            pro = 200 - pro;
            len = strlen(buff);
            for(i = 0; i < len; ++ i)
            {
                code[i] = key[buff[i] - 97];
            }
            for(i = 1; i <= len; ++ i)
            {
                itr1 = dic.find(string(code, code + i));
                if(itr1 != dic.end())
                {
                    itr2 = (itr1 -> second).find(pro);
                    if(itr2 != (itr1 -> second).end())
                        (itr2 -> second).insert(string(buff, buff + i));
                    else
                    {
                        set<string> t;
                        t.insert(string(buff, buff + i));
                        (itr1 -> second).insert(make_pair(pro, t));
                    }
                }
                else
                {
                    set<string> t;
                    t.insert(string(buff, buff + i));
                    map<int, set<string> > k;
                    k.insert(make_pair(pro, t));
                    dic.insert(make_pair(string(code, code + i), k));
                }
            }
        }
        scanf("%d", &input);
        while(input --)
        {
            scanf("%s", &buff);
            len = strlen(buff);
            for(i = 1; i < len; ++ i)
            {
                itr1 = dic.find(string(buff, buff + i));
                if(itr1 == dic.end()) printf("MANUALLY\n");
                else
                    cout<<*(((itr1 -> second).begin() -> second).begin())<<"\n";
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
