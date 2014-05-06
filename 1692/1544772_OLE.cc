#include<iostream>

int i, j, k, n1, n2, test;
int a1[100], a2[100];
int record[100][100];

int make(int p1, int p2, int p2s)
{
    if(record[p1][p2] != -1) return record[p1][p2];
    int maxm = 0, temp, r, g, rr, gg;
    bool flag = 0;
    if(a1[p1] == a2[p2])
    {
        for(r = p1 + 1; r < n1; ++ r)
            for(g = p2s; g < p2; ++ g)
                if(a1[r] == a2[g] && a1[p1] != a1[r])
                {// got one pair
                    flag = 1;
                    for(rr = r + 1; rr < n1; ++ rr)
                        for(gg = p2 + 1; gg < n2; ++ gg)
                            if((temp = 2 + make(rr, gg, p2 + 1)) > maxm)
                                maxm = temp;
                }
        if(flag) if(maxm < 2) maxm = 2;
    }
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
        for(i = k = 0; i < n1; ++ i) for(j = 0; j < n2; ++ j)
        {make(i, j, 0);std::cout<<i<<" "<<j<<"    "<<record[i][j]<<std::endl;
        if(record[i][j] > k) k = record[i][j];}
        printf("%d\n", k);
    }
    return 0;
}
