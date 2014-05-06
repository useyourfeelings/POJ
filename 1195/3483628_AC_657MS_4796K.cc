#include<iostream>
#include<vector>
using namespace std;

int sum[1100][1100];
int N;

void add(int x , int y , int val)
{
	int y1;
	while (x <= N)
    {
		y1 = y;
		while (y1 <= N)
        {
			sum[x][y1] += val;
			y1 += (y1 & -y1); 
		}
		x += (x & -x); 
	}
}

int getsum(int x, int y)
{
	int y1, s = 0;
	while (x > 0)
    {
		y1 = y;
		while (y1 > 0)
        {
			s += sum[x][y1];
			y1 -= (y1 & -y1); 
		}
		x -= (x & -x); 
	}
	return s;
}

int main()
{
    int command, L, B, R, T, i, j, s;
    scanf("%d%d", &i, &N);
    while(scanf("%d", &command))
    {
        if(command == 3) break;
        else if(command == 1)
        {
            scanf("%d%d%d", &L, &B, &T);
            add(L + 1, B + 1, T);
        }
        else
        {
            scanf("%d%d%d%d", &L, &B, &R, &T);
            ++ L;
            ++ B;
            ++ R;
            ++ T;
            s = getsum(R, T);
            if(L != 1) s -= getsum(L - 1, T);
            if(B != 1) s -= getsum(R, B - 1);
            if(L != 1 && B != 1) s += getsum(L - 1, B - 1);
            printf("%d\n", s);
        }
    }
    return 0;
}