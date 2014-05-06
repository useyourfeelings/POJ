#include<iostream>
using namespace std;

int org[100][100];
int temp[100][100];
int scenario, Scenario, n, i, mid;
int highest, lowest, high, low;

void init()
{
    int i, j;
    scanf("%d", &n);
    highest = 0;
    lowest = 200;
    for(i = 0; i < n; ++ i)
        for(j = 0; j < n; ++ j)
        {
            scanf("%d", &org[i][j]);
            if(org[i][j] > highest)
                highest = org[i][j];
            if(org[i][j] < lowest)
                lowest  = org[i][j];
        }
}

int search(int r, int c)
{
    if(r < 0 || r >= n || c < 0 || c >= n ||
       temp[r][c] == 1 || org[r][c] < low || org[r][c] > mid)
    return 0;
    temp[r][c] = 1;
    return (r == (n - 1) && c == (n - 1)) ||
            search(r + 1, c) ||
            search(r - 1, c) ||
            search(r, c + 1) ||
            search(r, c - 1);
}

int mindiff()
{
    init();
    int best = 200;
    for(low = lowest; low <= highest; ++ low)
    {
        i = low;
        high = highest + 1;
        while(i < high)
        {
            memset(temp, 0, sizeof(temp));
            mid = (i + high) / 2;
            if(search(0, 0)) high = mid;
            else
            {
                if(mid - low >= best) break;
                i  = mid + 1;
            }
        }
        if(high != highest + 1)
            if(high - low < best) best = high - low;
    }
    return best;
}

int main()
{
    scanf("%d", &Scenario);
    for(scenario = 1; scenario <= Scenario; ++ scenario)
    {
        printf("Scenario #%d:\n%d\n\n", scenario, mindiff());
    }
    return 0;
}