#include<iostream>
using namespace std;

int all1[5];
int all2[5];
int s1[9] = {25, 10, 5, 1}; // q d n p sum
int s2[9] = {10, 25, 5, 1};

bool make(int s[], int all[])
{
    int i, t, c = all[4];
    s[8] = 0;
    if(c == 0)
    {
        s[4] = s[5] = s[6] = s[7] = 0;
        return 1;
    }
    for(i = 0; i < 4; ++ i)
    {
        t = c / s[i];
        if(all[i] >= t)
        {
            c -= s[i] * t;
            s[i + 4] = t;
        }
        else
        {
            c -= s[i] * all[i];
            s[i + 4] = all[i];
        }
        if(c == 0)
        {
            int j;
            for(j = 0; j <= i; ++ j) s[8] += s[j + 4];
            for(; j < 4; ++ j)
                s[j + 4] = 0;
            return 1;
        }
    }
    return 0;
}

int main()
{
    while(scanf("%d%d%d%d%d", &all1[0], &all1[1], &all1[2], &all1[3],
        &all1[4]) && !(all1[0] == 0 && all1[1] == 0 &&
          all1[2] == 0 && all1[3] == 0 && all1[4] == 0))
    {
        all2[0] = all1[1]; all2[1] = all1[0]; all2[2] = all1[2];
        all2[3] = all1[3]; all2[4] = all1[4];
        if(make(s1, all1))
        {
            if(make(s2, all2))
            {
                if(s1[8] <= s2[8])
                    printf("Dispense %d quarters, %d dimes, %d nickels, "
                           "and %d pennies.\n", s1[4], s1[5], s1[6], s1[7]);
                else printf("Dispense %d quarters, %d dimes, %d nickels, "
                            "and %d pennies.\n", s2[5], s2[4], s2[6], s2[7]);
            }
            else printf("Dispense %d quarters, %d dimes, %d nickels, "
                        "and %d pennies.\n", s1[4], s1[5], s1[6], s1[7]);
        }
        else
        {
            if(make(s2, all2))
            {
                printf("Dispense %d quarters, %d dimes, %d nickels, "
                       "and %d pennies.\n", s2[5], s2[4], s2[6], s2[7]);
            }
            else printf("Cannot dispense the desired amount.\n");
        }
    }
    return 0;
}