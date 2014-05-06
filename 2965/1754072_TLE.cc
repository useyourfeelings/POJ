#include<iostream>
#include<algorithm>
#include<limits>
#include<vector>
using namespace std;

vector<bool> handle(16, 0);
vector<int> result(16, 0);
vector<int> current(16, 0);
int minswitch = INT_MAX;

int toFlip[16][7] = {{0, 1, 2, 3, 4, 8, 12}, {0, 1, 2, 3, 5, 9, 13},
                     {0, 1, 2, 3, 6, 10, 14}, {0, 1, 2, 3, 7, 11, 15},
                     {4, 5, 6, 7, 0, 8, 12}, {4, 5, 6, 7, 1, 9, 13},
                     {4, 5, 6, 7, 2, 10, 14}, {4, 5, 6, 7, 3, 11, 15},
                     {8, 9, 10, 11, 0, 4, 12}, {8, 9, 10, 11, 1, 5, 13},
                     {8, 9, 10, 11, 2, 6, 14}, {8, 9, 10, 11, 3, 7, 15},
                     {12, 13, 14, 15, 0, 4, 8}, {12, 13, 14, 15, 1, 5, 9},
                     {12, 13, 14, 15, 2, 6, 10}, {12, 13, 14, 15, 3, 7, 11}};

void make(int id)
{
    int i;
    if(id >= 16)
    {
        for(i = 0; i < 16; ++ i)
        {
            if(!handle[i]) break;
        }
        if(i >= 16) // got one
        {
            int total;
            for(i = total = 0; i < 16; ++ i) total += current[i];
            if(total < minswitch)
            {
                minswitch = total;
                copy(current.begin(), current.end(), result.begin());
            }
        }
        return;
    }
    
    make(id + 1);
    for(i = 0; i < 7; ++ i)
        handle[toFlip[id][i]].flip();
    ++ current[id];
    
    make(id + 1);
    
    for(i = 0; i < 7; ++ i)
        handle[toFlip[id][i]].flip();
    -- current[id];
}

int main()
{
    int i;
    char t;
    for(i = 0; i < 16; ++ i)
    {
        scanf("%c", &t);
        if(t == '-') handle[i].flip();
        if((i + 1) % 4 == 0) getchar();
    }
    make(0);
    printf("%d", minswitch);
    for(i = 0; i < 16; ++ i)
    {
        if(result[i])
            printf("\n%d %d", i / 4 + 1, i % 4 + 1);
    }
    return 0;
}