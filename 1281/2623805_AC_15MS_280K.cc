#include<iostream>
#include<algorithm>
#include<set>
using namespace std;

int i, len, pos, arg, policy, remove_count;
char command;
int list[256];

int main()
{
    while(scanf("%d", &len) != EOF)
    {
        scanf("%d", &len);
        for(i = 0; i < len; ++ i) scanf("%d", &list[i]);
        sort(list, list + len);
        multiset<int> job;
        policy = 1;
        remove_count = 0;
        pos = 0;
        scanf("%c", &command);
        while(scanf("%c", &command) && command != 'e')
        {
            if(command == 'a')
            {
                scanf("%d", &arg);
                job.insert(arg);
            }
            else if(command == 'r')
            {
                if(job.empty()) continue;
                ++ remove_count;
                if(remove_count == list[pos])
                {
                    if(policy == 1) printf("%d\n", * job.begin());
                    else            printf("%d\n", * (-- job.end()));
                    ++ pos;
                }
                if(policy == 1) job.erase(job.begin());
                else            job.erase(-- job.end());
            }
            else if(command == 'p')
            {
                scanf("%d", &arg);
                policy = arg;
            }
        }
        printf("\n");
    }
    return 0;
}
