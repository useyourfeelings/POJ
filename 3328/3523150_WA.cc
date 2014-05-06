#include<iostream>
#include<climits>
using namespace std;

char map[64][32];
int R, C, RC;

int HeapSize;
int HeapOfIndex[3601];     //  if HeapOfIndex[x] == 0 then HeapOfIndex[x] is empty
int PositionOfIndex[3601];
int ValueOfIndex[3601];    // distance to source

void MinHeapifyUp(int pos)   // go up from pos
{
    int parent = pos / 2;
    int t;
    while(parent >= 1 &&
           ValueOfIndex[HeapOfIndex[parent]] > ValueOfIndex[HeapOfIndex[pos]])
    {
        PositionOfIndex[HeapOfIndex[parent]] = pos; // change PositionOfIndex
        PositionOfIndex[HeapOfIndex[pos]]    = parent;
        t = HeapOfIndex[parent];                    // swap index
        HeapOfIndex[parent] = HeapOfIndex[pos];
        HeapOfIndex[pos] = t;
        pos = parent;                               // go on
        parent /= 2;
    }
}

void MinHeapifyDown(int now)   // go down from pos
{
    int l, r, smaller, t;
    for(;;) // go down       index of the smaller value go up
    {
        l = now * 2;
        r = l + 1;
        if(l > HeapSize) l = 0;
        if(r > HeapSize) r = 0;
        if(ValueOfIndex[HeapOfIndex[l]] == INT_MAX &&
           ValueOfIndex[HeapOfIndex[r]] == INT_MAX)
        {
            break; // reach bottom
        }
        if(ValueOfIndex[HeapOfIndex[l]] <= ValueOfIndex[HeapOfIndex[r]]) // left child go up
            smaller = l;
        else smaller = r;                      // right child go up
        PositionOfIndex[HeapOfIndex[smaller]] = now; // change PositionOfIndex
        PositionOfIndex[HeapOfIndex[now]] = smaller;
        t = HeapOfIndex[now];                    // swap index
        HeapOfIndex[now] = HeapOfIndex[smaller];
        HeapOfIndex[smaller] = t;
        now = smaller;                         // go on
    }
}

int HeapExtractIndexOfMinValue()
{
    int MinIndex = HeapOfIndex[1];
    HeapOfIndex[1] = HeapOfIndex[HeapSize];
    -- HeapSize;
    if(HeapSize != 0) MinHeapifyDown(1);
    return MinIndex;
}

void HeapDecreaseKey(int index, int NewKey)
{
    ValueOfIndex[index] = NewKey;         // decrease key
    MinHeapifyUp(PositionOfIndex[index]); // heapify up
}

void HeapInsert(int index, int value)
{
    ++ HeapSize;
    PositionOfIndex[index] = HeapSize;
    HeapOfIndex[HeapSize] = index;
    ValueOfIndex[index] = value;
    MinHeapifyUp(HeapSize);
}

int pattern[2][9][2] = {{{-2, 1}, {-1, 1}, {-1, 2}, {0, 1}, {0, 2}, {0, 3}, {1, 1}, {1, 2}, {2, 1}}, 
               {{-2, -1}, {-1, -1}, {-1, -2}, {0, -1}, {0, -2}, {0, -3}, {1, -1}, {1, -2}, {2, -1}}};

void Init()
{
    for(int i = RC * 2; i >= 0; -- i) ValueOfIndex[i] = INT_MAX;
    HeapSize = 0;
}

int Dijkstra(int start)
{
    Init();
    HeapInsert(start, 0);
    int index, value, adjindex;
    int i, j, q, p, k, pi, d, adj;
    while(HeapSize > 0)
    {
        index = HeapExtractIndexOfMinValue();
        value = ValueOfIndex[index];
        if(index > RC)
        {
            pi = 1, adj = 0;   // next left  leg
            i = (index - RC - 1) / C;
            j = (index - RC - 1) % C;
        }
        else
        {
            pi = 0, adj =  RC; // next right leg
            i = (index - 1) / C;
            j = (index - 1) % C;
        }
        for(k = 0; k < 9; ++ k)
        {
            p = i + pattern[pi][k][0];
            q = j + pattern[pi][k][1];
            if(p < 0 || p >= R || q < 0 || q >= C) continue;
            if(map[p][q] == 'X' || map[p][q] == 'S') continue;
            if(map[p][q] == 'T') return value;      // finish
            adjindex = p * C + q + adj + 1;
            d = value + map[p][q] - 48;
            if(d < ValueOfIndex[adjindex])
            {
                if(ValueOfIndex[adjindex] == INT_MAX) // new node
                    HeapInsert(adjindex, d);
                else HeapDecreaseKey(adjindex, d);
            }
        }
    }
    return -1;
}

int main()
{
    int i, j, result;
    while(scanf("%d%d\n", &C, &R) && C != 0)
    {
        RC = R * C;
        for(i = 0; i < R; ++ i)
        {
            for(j = 0; j < C - 1; ++ j)
                scanf("%c ", &map[i][j]);
            scanf("%c\n", &map[i][j]);
        }
        result = INT_MAX;
        for(i = 0; i < C; ++ i)
        {
            if(map[R - 1][i] == 'S')
            {
                j = Dijkstra((R - 1) * C + i + 1);
                if(j != -1 && j < result) result = j;
                j = Dijkstra((R - 1) * C + i + 1 + RC);
                if(j != -1 && j < result) result = j;
            }
        }
        if(result == INT_MAX) result = -1;
        printf("%d\n", result);
    }
    return 0;
}