#include<iostream>
#include<limits>
using namespace std;

int v, p, i, j;
int OnePostMin[300][300];
int village[300];
int record[300][30];

void CalcOnePostMin()
{
    int i, j, k, g, min, sum;
    for(i = 0; i < v; ++ i)
    {
        for(j = i; j < v; ++ j)
        {
            min = INT_MAX;
            for(k = i; k <= j; ++ k)
            {
                sum = 0;
                for(g = i; g < k; ++ g) sum += (village[k] - village[g]);
                for(g = k + 1; g <= j; ++ g) sum += village[j] - village[k];
                if(sum < min) min = sum;
            }
            OnePostMin[i][j] = min;
        }
    }
}

int make(int end, int postNo)
{
    if(record[end][postNo] != -1) return record[end][postNo];
    int i, min = INT_MAX, t;
    for(i = postNo - 1; i <= end - 1; ++ i)
    {
        t = make(i, postNo - 1) + OnePostMin[i + 1][end];
        if(t < min) min = t;
    }
    record[end][postNo] = min;
    return min;
}

int main()
{
    scanf("%d%d", &v, &p);
    for(i = 0; i < v; ++ i) scanf("%d", &village[i]);
    
    for(i = 0; i < v; ++ i)
        for(j = 0; j <= p; ++ j) record[i][j] = -1;
    
    CalcOnePostMin();
    
    for(i = 0; i < v; ++ i) record[i][1] = OnePostMin[0][i];
    for(i = 0; i < p; ++ i) record[p][p] = 0;
    
    printf("%d", make(v - 1, p));
    return 0;
}
