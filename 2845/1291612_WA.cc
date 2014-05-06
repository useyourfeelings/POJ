#include<iostream>
using namespace std;
char a[82];
char b[82];
int main()
{   
    int t, i, j, e, s1, s2;
    scanf("%d", &t);
    for(i = 1; i <= t; ++ i)
    {
        a[0] = b[0] = '0';
        cin>>(a + 1)>>(b + 1);
        s1 = strlen(a) - 1;
        s2 = strlen(b) - 1;
        if(s1 >= s2)
        {
            e = s1;
            for(; s2 >= 1; -- s1, -- s2)
            {
                a[s1 - 1] += (int(a[s1]) + int(b[s2]) - 96) / 2;
                a[s1] = (int(a[s1]) + int(b[s2]) - 96) % 2 + 48;
            }
            for(; s1 >= 1 && a[s1] > '1'; -- s1)
            {
                a[s1 - 1] += 1;
                a[s1] -= 2;
            }
            for(s1 = 0; s1 < e; ++ s1)
                if(a[s1] != '0') break;
            if(s1 == e)
            {
                printf("%d 0\n", i);
                continue;
            }
            printf("%d ", i);
            for(; s1 <= e; ++ s1) printf("%c", a[s1]);
            printf("\n");
        }
        else
        {
            e = s2;
            for(; s1 >= 1; -- s1, -- s2)
            {
                b[s2 - 1] += (int(b[s2]) + int(a[s1]) - 96) / 2;
                b[s2] = (int(b[s2]) + int(a[s1]) - 96) % 2 + 48;
            }
            for(; s2 >= 1 && b[s2] > '1'; -- s2)
            {
                b[s2 - 1] += 1;
                b[s2] -= 2;
            }
            for(s2 = 0; s2 < e; ++ s2)
                if(b[s2] != '0') break;
            if(s2 == e)
            {
                printf("%d 0\n", i);
                continue;
            }
            printf("%d ", i);
            for(; s2 <= e; ++ s2) printf("%c", b[s2]);
            printf("\n");
        }
    }
    return 0;
}