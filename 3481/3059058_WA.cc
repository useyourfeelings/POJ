#include<iostream>
#include<map>
using namespace std;

map<int, int> C;
map<int, int>::iterator i;
int command, client, p, answer;

int main()
{
    while(scanf("%d", &command) && command != 0)
    {
        if(command == 1)
        {
            scanf("%d%d", &p, &client);
            C.insert(make_pair(p, client));
            continue;
        }
        else if(command == 2)
        {
            if(C.empty()) answer = 0;
            else
            {
                answer = C.begin() -> first;
                C.erase(C.begin());
            }
        }
        else
        {
            if(C.empty()) answer = 0;
            else
            {
                answer = C.rbegin() -> first;
                i = C.end();
                -- i;
                C.erase(i);
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}