#include<iostream>
using namespace std;

int tree[70000][2];
int countt[15000];

void build(int a, int b, int room)
{
    if(a > b) return;
    int mid = (a + b) / 2;
    tree[room][0] = mid;
    build(a, mid - 1, room * 2 + 1);
    build(mid + 1, b, room * 2 + 2);
}
void insert(int id, int c, int room)
{
    if(id == tree[room][0])
    {
        c += tree[room][1];
        tree[room][1] ++;
        countt[c] ++;
    }
    else
    {
        if(id < tree[room][0])
        {
            tree[room][1] ++;
            insert(id, c, room * 2 + 1);
        }
        else insert(id, c + tree[room][1], room * 2 + 2);
    }
}

int main()
{   
    int n, x, y, i;
    build(0, 32767, 0);
    cin>>n;
    for(i = 0; i < n; i++) countt[i] = 0;
    for(i = 0; i < 32768; i++) tree[i][1] = 0;
    for(i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        insert(x, 0, 0);
    }
    for(x = 0; x < n; x++) cout<<countt[x]<<endl;
    return 0;
}