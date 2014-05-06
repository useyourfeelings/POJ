#include<iostream>
using namespace std;

int willget[12][10001];
int weight[12], value[12], total_weight[12];
int N, D, i, j;

// max possible value ( ith stone, B's weight is j )
int most(int i, int j)
{
    if(i >= N) return 0;
    if(willget[i][j] != -2) return willget[i][j];
    int weight_A = total_weight[i - 1] - j;
    int best_A = -1, best_B = -1;
    if(weight_A + weight[i] < D + j) // could go A
    {
        best_A = most(i + 1, j);
    }
    if(j + weight[i] < D + weight_A) // could go B
    {
        best_B = value[i] + most(i + 1, j + weight[i]);
    }
    if(best_A < best_B) best_A = best_B;
    willget[i][j] = best_A;
    return best_A;
}

int main()
{
    scanf("%d%d", &N, &D);
    for(i = 0; i < N; ++ i)
        scanf("%d%d", &weight[i], &value[i]);
    total_weight[0] = weight[0];
    for(i = 1; i < N; ++ i)
        total_weight[i] = total_weight[i - 1] + weight[i];
    for(i = 0; i < N; ++ i)
        for(j = 0; j < 10001; ++ j)
            willget[i][j] = -2;
    printf("%d\n", most(1, 0));
    return 0;
}