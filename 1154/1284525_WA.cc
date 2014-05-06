#include<iostream>
#include<vector>
using namespace std;

char b[20][20];
int R, C, i;

int make(int r, int c, vector<bool> done)
{
    if(done[b[r][c] - 65]) return 0;
    int v1 = -1, v2 = -1, v3 = -1, v4 = -1;
    done[b[r][c] - 65] = 1;
    if(r > 0)     v1 = make(r - 1, c, done);
    if(r < R - 1) v2 = make(r + 1, c, done);
    if(c > 0)     v3 = make(r, c - 1, done);
    if(c < C - 1) v4 = make(r, c + 1, done);
    v1 = max(v1, v2);
    v1 = max(v1, v3);
    return max(v1, v4) + 1;
}

int main()
{
    scanf("%d%d", &R, &C);
    getchar();
    for(i = 0; i < R; ++i) gets(b[i]);
    vector<bool> done(26, 0);
    cout<<make(0, 0, done)<<endl;
    return 0;
}