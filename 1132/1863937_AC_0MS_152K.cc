#include<iostream>
using namespace std;

int main()
{
    int test, t, x, y, i;
    char move[1024];
    char bmp[32][32];
    scanf("%d", &test);
    for(t = 1; t <= test; ++ t)
    {
        for(x = 0; x < 32; ++ x)
            for(y = 0; y < 32; ++ y) bmp[x][y] = '.';
        scanf("%d%d", &x, &y);
        getchar();
        scanf("%s", move);
        i = 0;
        while(move[i] != '.')
        {
            if(move[i] == 'E')
            {
                bmp[32 - y][x] = 'X';
                ++ x;
            }
            else if(move[i] == 'N')
            {
                bmp[31 - y][x] = 'X';
                ++ y;
            }
            else if(move[i] == 'W')
            {
                bmp[31 - y][x - 1] = 'X';
                -- x;
            }
            else
            {
                bmp[32 - y][x - 1] = 'X';
                -- y;
            }
            ++ i;
        }
        printf("Bitmap #%d\n", t);
        for(x = 0; x < 32; ++ x)
        {
            for(y = 0; y < 32; ++ y) printf("%c", bmp[x][y]);
            printf("\n");
        }
        printf("\n");
    }
    system("pause");
    return 0;
}