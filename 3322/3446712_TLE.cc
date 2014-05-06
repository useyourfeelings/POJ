#include<iostream>
#include<list>
using namespace std;

struct Node
{
    Node(int rr, int cc, int ss):r(rr),c(cc),state(ss){}
    int r;
    int c;
    int state; // 0 - stand up   1 - lay down (|)  2 - lay down(-)
};

char map[3][512][512];
int pattern[3][4][3];
int R, C;
list<Node> queue;

int main()
{
    while(scanf("%d", &R) && R != 0)
    {
        queue.clear();
        scanf("%d", &C);
        int i, j, step, newnode;// ii, jj, t, s, ss, step;
        for(i = 0; i < R; ++ i) scanf("%s", map[0][i]);
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j)
                map[1][i][j] = map[0][i][j];
        for(i = 0; i < R; ++ i)
            for(j = 0; j < C; ++ j)
                map[2][i][j] = map[1][i][j];
        //for(i = 0; i < R; ++ i) printf("%s\n", map[0][i]);
        R -= 2;
        C -= 2;
        for(i = 1; i <= R; ++ i)
        {
            for(j = 1; j <= C; ++ j)
                if(map[0][i][j] == 'X') break;
            if(map[0][i][j] == 'X') break;
        }
        if(map[0][i][j + 1] == 'X')
        {
            queue.push_back(Node(i, j, 2));
            map[2][i][j] = 'S';
        }
        else if(map[0][i + 1][j] == 'X')
        {
            queue.push_back(Node(i, j, 1));
            map[1][i][j] = 'S';
        }
        else
        {
            queue.push_back(Node(i, j, 0));
            map[0][i][j] = 'S';
        }
        for(step = 0, newnode = 1;; ++ step)
        {
            if(queue.empty())
            {
                step = -1;
                break;
            }
            int x = newnode;
            newnode = 0;
            for(; x > 0; -- x)
            {
                i = queue.front().r;
                j = queue.front().c;
                switch(queue.front().state)
                {
                    case 0:
                        if(map[1][i - 2][j] != 'S')
                        {
                            if(map[1][i - 2][j] != '#' && map[1][i - 1][j] != '#')
                            {
                                queue.push_back(Node(i - 2, j, 1));
                                map[1][i - 2][j] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[1][i + 1][j] != 'S')
                        {
                            if(map[1][i + 1][j] != '#' && map[1][i + 2][j] != '#')
                            {
                                queue.push_back(Node(i + 1, j, 1));
                                map[1][i + 1][j] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[2][i][j - 2] != 'S')
                        {
                            if(map[2][i][j - 2] != '#' && map[2][i][j - 1] != '#')
                            {
                                queue.push_back(Node(i, j - 2, 2));
                                map[2][i][j - 2] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[2][i][j + 1] != 'S')
                        {
                            if(map[2][i][j + 1] != '#' && map[2][i][j + 2] != '#')
                            {
                                queue.push_back(Node(i, j + 1, 2));
                                map[2][i][j + 1] = 'S';
                                ++ newnode;
                            }
                        }
                        break;
                    
                    case 1:
                        if(map[0][i - 1][j] == 'O' || map[0][i + 2][j] == 'O') goto done;
                        if(map[0][i - 1][j] != 'S')
                        {
                            if(map[0][i - 1][j] == '.')
                            {
                                queue.push_back(Node(i - 1, j, 0));
                                map[0][i - 1][j] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[0][i + 2][j] != 'S')
                        {
                            if(map[0][i + 2][j] == '.')
                            {
                                queue.push_back(Node(i + 2, j, 0));
                                map[0][i + 2][j] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[1][i][j - 1] != 'S')
                        {
                            if(map[1][i][j - 1] != '#' && map[1][i + 1][j - 1] != '#')
                            {
                                queue.push_back(Node(i, j - 1, 1));
                                map[1][i][j - 1] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[1][i][j + 1] != 'S')
                        {
                            if(map[1][i][j + 1] != '#' && map[1][i + 1][j + 1] != '#')
                            {
                                queue.push_back(Node(i, j + 1, 1));
                                map[1][i][j + 1] = 'S';
                                ++ newnode;
                            }
                        }
                        break;
                    
                    case 2:
                        if(map[0][i][j - 1] == 'O' || map[0][i][j + 2] == 'O') goto done;
                        if(map[2][i - 1][j] != 'S')
                        {
                            if(map[2][i - 1][j] != '#' && map[2][i - 1][j + 1] != '#')
                            {
                                queue.push_back(Node(i - 1, j, 2));
                                map[2][i - 1][j] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[2][i + 1][j] != 'S')
                        {
                            if(map[2][i + 1][j] != '#' && map[2][i + 1][j + 1] != '#')
                            {
                                queue.push_back(Node(i + 1, j, 2));
                                map[2][i + 1][j] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[0][i][j - 1] != 'S')
                        {
                            if(map[0][i][j - 1] == '.')
                            {
                                queue.push_back(Node(i, j - 1, 0));
                                map[0][i][j - 1] = 'S';
                                ++ newnode;
                            }
                        }
                        if(map[0][i][j + 2] != 'S')
                        {
                            if(map[0][i][j + 2] == '.')
                            {
                                queue.push_back(Node(i, j + 2, 0));
                                map[0][i][j + 2] = 'S';
                                ++ newnode;
                            }
                        }
                        break;
                }
                queue.pop_front();
            }
        }
        done :
        if(step == -1) printf("Impossible\n");
        else           printf("%d\n", step + 1);
    }
    return 0;
}
