#include<iostream>

int i, j, n1, n2, test;
int a1[100], a2[100];
int record[100][100];

int make(int p1, int p2)
{
    if(record[p1][p2] != -1) return record[p1][p2];
    int maxm = 0, temp, r, g;
    if(a1[p1] != a2[p2])
    {
        for(r = p1 + 1; r < n1; ++ r) if(a1[r] == a2[p2]) break;
        for(g = p2 + 1; g < n2; ++ g) if(a2[g] == a1[p1]) break;
        if(r < n1 && g < n2) maxm = 2;
        if(r < n1 - 2 && g < n2 - 2) maxm = 2 + make(r + 1, g + 1);
    }
    if(p1 < n1 - 2) if((temp = make(p1 + 1, p2)) > maxm) maxm = temp;
    if(p2 < n2 - 2) if((temp = make(p1, p2 + 1)) > maxm) maxm = temp;
    record[p1][p2] = maxm;
    return maxm;
}

int main()
{
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d%d", &n1, &n2);
        for(i = 0; i < n1; ++ i) scanf("%d", &a1[i]);
        for(j = 0; j < n2; ++ j) scanf("%d", &a2[j]);
        for(i = 0; i < n1; ++ i) for(j = 0; j < n2; ++ j) record[i][j] = -1;
        printf("%d\n", make(0, 0));
    }
    system("pause");
    return 0;
}
