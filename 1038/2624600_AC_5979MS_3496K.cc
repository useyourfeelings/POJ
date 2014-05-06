#include<iostream>
using namespace std;

int power[] ={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int M, N, K, i, j, p, Case, x, y, temp, tempbest, curr, p1, p2;
bool board[150][10];
int best[4][59049], nice[10], bit[10][59049];

void dobit()
{
    for(i = 0; i < 10; ++ i)
        for(j = 0; j < 59049; ++ j)
            bit[i][j] = (j / power[i]) % 3;
}

void init()
{
    scanf("%d%d%d", &N, &M, &K);
    for(i = 0; i < N; ++ i)
        for(j = 0; j < M; ++ j)
            board[i][j] = 0;
    while(K --)
    {
        scanf("%d%d", &x, &y);
        board[x - 1][y - 1] = 1;
    }
    for(i = 0; i < M; ++ i)
        nice[i] = 1 - board[0][i];
}

void run()
{
    for(i = 0; i < 4; ++ i)
        for(j = power[M]; j >= 0; -- j)
            best[i][j] = 0;
    curr = 0;
    for(i = 1; i < N; ++ i)
    {
        for(j = 0; j < M; ++ j)
        {
            if(!board[i][j]) ++ nice[j];
            else             nice[j] = 0;
            curr = (curr + 1) % 4;
            p1 = 2 * power[j] + 2 * power[j - 1];
            p2 = power[j] + power[j - 1] + power[j - 2];
            for(p = power[M] - 1; p >= 0; -- p)
            {
                if(bit[j][p] > 0)
                {
                    best[curr][p] = best[(curr + 3) % 4][p - power[j]];;
                    continue; // cant put anything
                }
                tempbest = best[(curr + 3) % 4][p];
                if(i >= 2 && j >= 1 && bit[j - 1][p] == 0 &&
                   nice[j] > 2 && nice[j - 1] > 2) // can put 3 * 2 plate
                {
                    if((temp = 1 + best[(curr + 2) % 4][p + p1]) > tempbest)
                        tempbest = temp;
                }
                if(i >= 1 && j >= 2 && bit[j - 1][p] == 0 && bit[j - 2][p] == 0 &&
                   nice[j] > 1 && nice[j - 1] > 1 && nice[j - 2] > 1) // can put 2 * 3 plate
                {
                    if((temp = 1 + best[(curr + 1) % 4][p + p2]) > tempbest)
                        tempbest = temp;
                }
                best[curr][p] = tempbest;
            }
        }
    }
}

int main()
{
    dobit();
    scanf("%d", &Case);
    while(Case --)
    {
        init();
        run();
        printf("%d\n", best[curr][0]);
    }
    return 0;
}