#include<iostream>
using namespace std;

int power[] ={1, 3, 9, 27, 81, 243, 729, 2187, 6561, 19683, 59049};
int M, N, K, i, j, p, Case, x, y, temp, tempbest, curr;
bool board[150][10];
int best[4][59049];

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
            curr = (curr + 1) % 4;
            for(p = power[M] - 1; p >= 0; -- p)
            {
                if((p / power[j]) % 3 > 0)
                {
                    best[curr][p] = best[(curr + 3) % 4][p - power[j]];;
                    continue; // cant put anything
                }
                tempbest = best[(curr + 3) % 4][p];
                if(i >= 2 && j >= 1 && (p / power[j - 1]) % 3 == 0 &&
                   board[i][j]     + board[i - 1][j]     + board[i - 2][j] +
                   board[i][j - 1] + board[i - 1][j - 1] + board[i - 2][j - 1] == 0) // can put 3 * 2 plate
                {
                    if((temp = 1 + best[(curr + 2) % 4][p + 2 * power[j] + 2 * power[j - 1]]) > tempbest)
                        tempbest = temp;
                }
                if(i >= 1 && j >= 2 && (p / power[j - 1]) % 3 == 0 && (p / power[j - 2]) % 3 == 0 &&
                   board[i][j]     + board[i][j - 1]     + board[i][j - 2] +
                   board[i - 1][j] + board[i - 1][j - 1] + board[i - 1][j - 2] == 0) // can put 2 * 3 plate
                {
                    if((temp = 1 + best[(curr + 1) % 4][p + power[j] + power[j - 1] + power[j - 2]]) > tempbest)
                        tempbest = temp;
                }
                best[curr][p] = tempbest;
            }
        }
    }
}

int main()
{
    scanf("%d", &Case);
    while(Case --)
    {
        init();
        run();
        printf("%d\n", best[curr][0]);
    }
    return 0;
}