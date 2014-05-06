#include<iostream>
#include<vector>
using namespace std;

// 1 fill 1; 2 fill 2; 3 drop 1; 4 drop 2; 5 pour 1, 2; 6 pour 2, 1
int done[101][101][3], queue[20000][2], end, newend, start, x, y;
vector<int> move;

int main()
{
    int A, B, C, a, b;
    scanf("%d%d%d", &A, &B, &C);
    if(A == C || B == C)
    {
        printf("1\n");
        if(A == C) printf("FILL(1)\n");
        else       printf("FILL(2)\n");
        return 0;
    }
    done[0][0][0] = 1;
    queue[0][0] = queue[0][1] = 0;
    start = 0;
    end = 1;
    while(start < end)
    {
        newend = end;
        for(; start < end; ++ start)
        {
            a = queue[start][0];
            b = queue[start][1];
            if(a != A && !done[A][b][0])
            {
                done[A][b][0] = 1;
                done[A][b][1] = a;
                done[A][b][2] = b;
                queue[newend][0] = A;
                queue[newend][1] = b;
                ++ newend;
            }
            if(b != B && !done[a][B][0])
            {
                done[a][B][0] = 2;
                done[a][B][1] = a;
                done[a][B][2] = b;
                queue[newend][0] = a;
                queue[newend][1] = B;
                ++ newend;
            }
            if(a != 0 && !done[0][b][0])
            {
                done[0][b][0] = 3;
                done[0][b][1] = a;
                done[0][b][2] = b;
                queue[newend][0] = 0;
                queue[newend][1] = b;
                ++ newend;
            }
            if(b != 0 && !done[a][0][0])
            {
                done[a][0][0] = 4;
                done[a][0][1] = a;
                done[a][0][2] = b;
                queue[newend][0] = a;
                queue[newend][1] = 0;
                ++ newend;
            }
            x = a - min(a, B - b); // 1 to 2
            y = min(a + b, B);
            if(x == C || y == C)
            {
                done[x][y][0] = 5;
                done[x][y][1] = a;
                done[x][y][2] = b;
                goto OK;
            }
            if(!done[x][y][0])
            {
                done[x][y][0] = 5;
                done[x][y][1] = a;
                done[x][y][2] = b;
                queue[newend][0] = x;
                queue[newend][1] = y;
                ++ newend;
            }
            x = min(b + a, A); // 2 to 1
            y = b - min(b, A - a);
            if(x == C || y == C)
            {
                done[x][y][0] = 6;
                done[x][y][1] = a;
                done[x][y][2] = b;
                goto OK;
            }
            if(!done[x][y][0])
            {
                done[x][y][0] = 6;
                done[x][y][1] = a;
                done[x][y][2] = b;
                queue[newend][0] = x;
                queue[newend][1] = y;
                ++ newend;
            }
        }
        end = newend;
    }
    OK:
    if(start == end)
    {
        printf("impossible\n");
        return 0;
    }
    move.reserve(end);
    while(x != 0 || y != 0)
    {
        move.push_back(done[x][y][0]);
        a = done[x][y][1];
        b = done[x][y][2];
        x = a;
        y = b;
    }
    printf("%d\n", move.size());
    for(a = move.size() - 1; a >= 0; -- a)
    {
        switch(move[a])
        {
            case 1: printf("FILL(1)\n"); break;
            case 2: printf("FILL(2)\n"); break;
            case 3: printf("DROP(1)\n"); break;
            case 4: printf("DROP(2)\n"); break;
            case 5: printf("POUR(1,2)\n"); break;
            case 6: printf("POUR(2,1)\n"); break;
        }
    }
    return 0;
}