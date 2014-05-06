#include<iostream>
#include<algorithm>
using namespace std;

struct brick
{
    int h, a, q;
};

bool operator<(const brick &x, const brick &y)
{
    return x.a < y.a;
}

int min(int a, int b)
{
	if(a < b)
		return a;
	return b;
}

brick bricks[400];
int rec[40000];      // flag
int possible[40000]; // todo list

int main()
{
    int i, p, j, K;
    int possiblesize = 1;
    int answer = 0, currHeight, newHeight;
    possible[0] = 0;

    scanf("%d", &K);
    for(i = 0; i < K; ++ i)
        scanf("%d%d%d", &bricks[i].h, &bricks[i].a, &bricks[i].q);
    sort(bricks, bricks + K);

    for(i = 0; i < K; ++ i)
    {
        for(p = possiblesize - 1; p >=0; -- p)
        {
            currHeight = possible[p];
            j = bricks[i].h * min(bricks[i].q, (bricks[i].a - currHeight) / bricks[i].h);
            for(; j >= 0; j -= bricks[i].h)
            {
                newHeight = j + currHeight;
                if(rec[newHeight] == 0)
                {
                    rec[newHeight] = 1;
                    possible[possiblesize ++] = newHeight;

                    if(newHeight > answer)
                        answer = newHeight;
                }
            }
        }
    }
    printf("%d", answer);
    return 0;
}