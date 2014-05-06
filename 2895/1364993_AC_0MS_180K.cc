#include<iostream>
using namespace std;

char dail[1000];
int group[26] = {21, 22, 23, 31, 32, 33, 41, 42, 43, 51, 52, 53,
                 61, 62, 63, 71, 72, 73, 74, 81, 82, 83, 91, 92, 93, 94};

int main()
{
    int i, n, p, w, sum;
    char last;
    scanf("%d", &n);
    getchar();
    while(n --)
    {
        scanf("%d%d", &p, &w);
        getchar();
        gets(dail);
        last = ' ';
        for(sum = i = 0; i < strlen(dail); ++ i)
        {
            if(last == ' ')
            {
                last = dail[i];
                if(dail[i] == ' ') sum += p;
                else sum += p * (group[last - 65] % 10);
            }
            else
            {
                if(dail[i] == ' ') sum += p;
                else
                {
                    if(group[last - 65] / 10 == group[dail[i] - 65] / 10)
                        sum += (w + p * (group[dail[i] - 65] % 10));
                    else sum += p * (group[dail[i] - 65] % 10);
                }
                last = dail[i];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
