#include<iostream>
using namespace std;

int L, N;
int car[512];
char best[128][128][512];
char move[128][128][512]; // 1 left    2 right   0 over

int MostCar(int left, int right, int pos) // left space   right space    car no.
{
    if(pos > N) return 0;
    if(best[left][right][pos] != -2) return best[left][right][pos];
    int goL = 0, goR = 0;
    if(left >= car[pos])  goL = 1 + MostCar(left - car[pos], right, pos + 1);
    if(right >= car[pos]) goR = 1 + MostCar(left, right - car[pos], pos + 1);
    if(goL < goR)
    {
        goL = goR;
        move[left][right][pos] = 2;
    }
    else
    {
        if(goL != 0) move[left][right][pos] = 1;
    }
    best[left][right][pos] = goL;
    return goL;
}

void show()
{
    printf("%d\n", best[L][L][1]);
    int i, j = L, k = L;
    for(i = 1;; ++ i)
    {
        if(move[j][k][i] == 1)
        {
            printf("port\n");
            j -= car[i];
        }
        else if(move[j][k][i] == 2)
        {
            printf("starboard\n");
            k -= car[i];
        }
        else break;
    }
}

int main()
{
    int i, j, k;
    scanf("%d", &L);
    for(N = 1;; ++ N)
    {
        scanf("%d", &car[N]);
        if(car[N] == 0) break;
    }
    -- N;
    for(i = 1; i <= N; ++ i) car[i] /= 100;
    for(i = 0; i < 128; ++ i)
        for(j = 0; j < 128; ++ j)
            for(k = 1; k <= N; ++ k)
                best[i][j][k] = -2;
    MostCar(L, L, 1);
    show();
    return 0;
}