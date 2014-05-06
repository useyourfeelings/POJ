#include<iostream>
using namespace std;

char card[12][5];
int i, j, k, c;

bool ok()
{
    if(  ( (card[i][0] == card[j][0] && card[i][0] == card[k][0]) ||
          (card[i][0] != card[j][0] && card[i][0] != card[k][0] &&
                                         card[j][0] != card[k][0])) &&
         ( (card[i][1] == card[j][1] && card[i][1] == card[k][1]) ||
          (card[i][1] != card[j][1] && card[i][1] != card[k][1] &&
                                         card[j][1] != card[k][1])) &&
         ( (card[i][2] == card[j][2] && card[i][2] == card[k][2]) ||
          (card[i][2] != card[j][2] && card[i][2] != card[k][2] &&
                                         card[j][2] != card[k][2])) &&
         ( (card[i][3] == card[j][3] && card[i][3] == card[k][3]) ||
          (card[i][3] != card[j][3] && card[i][3] != card[k][3] &&
                                         card[j][3] != card[k][3]))   )
        return true;
    return false;
}

int main()
{
    while(scanf("%s", card[0]) != EOF)
    {
        c = 0;
        for(i = 1; i < 12; ++ i)
            scanf("%s", card[i]);
        printf("CARDS: ");
        for(i = 0; i < 12; ++ i) printf(" %s", card[i]);
        printf("\nSETS:   ");
        for(i = 0; i <= 9; ++ i)
            for(j = i + 1; j <= 10; ++ j)
                for(k = j + 1; k <= 11; ++ k)
                {
                    if(ok())
                    {
                        ++ c;
                        if(c != 1) printf("        ");
                        printf("%d.  %c%c%c%c %c%c%c%c %c%c%c%c\n", c,
                        card[i][0], card[i][1], card[i][2], card[i][3],
                        card[j][0], card[j][1], card[j][2], card[j][3],
                        card[k][0], card[k][1], card[k][2], card[k][3]);
                    }
                }
        if(c == 0) printf("*** None Found ***\n");
        printf("\n");
    }
    return 0;
}