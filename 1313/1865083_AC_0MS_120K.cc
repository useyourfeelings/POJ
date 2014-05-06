#include<iostream>
using namespace std;

int main()
{
    int p, s, i;
    while(scanf("%d", &p) && p != 0)
    {
        printf("Printing order for %d pages:\n", p);
        s = p / 4;
        if(p % 4 != 0) ++ s;
        for(i = 1; i <= s; ++ i)
        {
            if((4 * s - (i - 1) * 2) <= p)
            {
                printf("Sheet %d, front: %d, %d\n",
                                  i, 4 * s - (i - 1) * 2, i * 2 - 1);
            }
            else
            {
                printf("Sheet %d, front: Blank, %d\n", i, i * 2 - 1);
            }
            if(i * 2 <= p)
            {
                printf("Sheet %d, back : %d, ", i, i * 2);
                if((4 * s - (i - 1) * 2 - 1) <= p)
                    printf("%d\n", 4 * s - (i - 1) * 2 - 1);
                else printf("Blank\n");
            }
        }
    }
    return 0;
}