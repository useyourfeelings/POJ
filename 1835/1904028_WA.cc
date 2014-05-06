#include<iostream>
using namespace std;

char cmd[8];
int turn[6][6][6][2] =
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    0, 1, 3, 1, 2, 1, 5, 1, 1, 3, 4, 0,
     0, 2, 3, 2, 4, 2, 1, 2, 2, 3, 5, 0,    0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 4, 3, 4, 5, 4, 2, 4, 4, 3, 1, 0,    0, 5, 1, 5, 1, 5, 4, 5, 5, 3, 2, 0,
     1, 0, 4, 0, 5, 0, 2, 0, 0, 4, 3, 1,    1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     1, 2, 4, 2, 0, 2, 3, 2, 2, 4, 5, 1,    1, 3, 4, 3, 2, 3, 5, 3, 3, 4, 0, 1,
     1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    1, 5, 4, 5, 3, 5, 0, 5, 5, 4, 2, 1,
     2, 0, 5, 0, 1, 0, 4, 0, 0, 5, 3, 2,    2, 1, 5, 1, 3, 1, 0, 1, 1, 5, 4, 2,
     2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    2, 3, 5, 3, 4, 3, 1, 3, 3, 5, 0, 2,
     2, 4, 5, 4, 0, 4, 3, 4, 4, 5, 1, 2,    2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    3, 1, 0, 1, 5, 1, 2, 1, 1, 0, 4, 3,
     3, 2, 0, 2, 1, 2, 4, 2, 2, 0, 5, 3,    3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     3, 4, 0, 4, 2, 4, 5, 4, 4, 0, 1, 3,    3, 5, 0, 5, 4, 5, 1, 5, 5, 0, 2, 3,
     4, 0, 1, 0, 2, 0, 5, 0, 0, 1, 3, 4,    4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     4, 2, 1, 2, 3, 2, 0, 2, 2, 1, 5, 4,    4, 3, 1, 3, 5, 3, 2, 3, 3, 1, 0, 4,
     4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    4, 5, 1, 5, 0, 5, 3, 5, 5, 1, 2, 4,
     5, 0, 2, 0, 4, 0, 1, 0, 0, 2, 3, 5,    5, 1, 3, 1, 0, 1, 3, 1, 1, 2, 4, 5,
     5, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    5, 3, 2, 3, 1, 3, 4, 3, 3, 2, 0, 5,
     5, 4, 2, 4, 3, 4, 0, 4, 4, 2, 1, 5,    5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int move[6][3] = 
{1, 0, 0,   0, 1, 0,   0, 0, 1,   -1, 0, 0,   0, -1, 0,   0, 0, -1};

int c[] = {0, 1, 0, 5, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 3, 0, 0, 4};

int main()
{
    int test, n, x, y, z, len, face, head, f;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d", &n);
        face = x = y = z = 0;
        head = 2;
        while(n --)
        {
            scanf("%s%d", cmd, &len);
            f = face;
            face = turn[f][head][c[cmd[0] - 97]][0];
            head = turn[f][head][c[cmd[0] - 97]][1];
            x += len * move[face][0];
            y += len * move[face][1];
            z += len * move[face][2];
        }
        printf("%d %d %d %d\n", x, y, z, face);
    }
    return 0;
}