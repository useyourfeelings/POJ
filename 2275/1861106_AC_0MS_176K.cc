//   2275 Flipping Pancake

#include<iostream>
#include<limits>
#include<algorithm>
#include<vector>
using namespace std;

int cake[31];
vector<int> sequence;
int total;

void flip(int k)
{
    for(int i = 1; i <= k; ++ i, -- k) swap(cake[i], cake[k]);
}

void reverseMake(int n, int head, int tail);

void Make(int n, int head, int tail)
{
    if(n == 1) return;
    if(cake[n] == tail)
    {
        Make(n - 1, head, tail - 1);
        return;
    }
    if(cake[n] == head)
    {
        reverseMake(n - 1, head + 1, tail);
        sequence.push_back(n); // last step : flip(n);
        ++ total;
        return;
    }
    int i = 1;
    while(cake[i] != tail) ++ i;
    if(i != 1)
    {
        flip(i);
        sequence.push_back(i);
        ++ total;
    }
    flip(n);
    sequence.push_back(n);
    ++ total;
    Make(n - 1, head, tail - 1);
}

void reverseMake(int n, int head, int tail)
{
    if(n == 1) return;
    if(cake[n] == head)
    {
        reverseMake(n - 1, head + 1, tail);
        return;
    }
    if(cake[n] == tail)
    {
        Make(n - 1, head, tail - 1);
        sequence.push_back(n); // last step : flip(n);
        ++ total;
        return;
    }
    int i = 1;
    while(cake[i] != head) ++ i;
    if(i != 1)
    {
        flip(i);
        sequence.push_back(i);
        ++ total;
    }
    flip(n);
    sequence.push_back(n);
    ++ total;
    reverseMake(n - 1, head + 1, tail);
}

int main()
{
    int i, n;
    sequence.reserve(60);
    while(cin>>n && n != 0)
    {
        sequence.clear();
        total = 0;
        for(i = 1; i <= n; ++ i)
            cin>>cake[i];
        Make(n, 1, n);
        printf("%d", total);
        for(i = 0; i <sequence.size(); ++ i)
            printf(" %d", sequence[i]);
        printf("\n");
    }
    return 0;
}