#include<iostream>
#include<vector>
using namespace std;
short g[101][101];
int kase, r, c, n, m, x, y, i;
char d;
struct robot
{
    robot(short xx, short yy, char dd):xp(xx),yp(yy),dead(0)
    {
        da[0] = 'E'; da[1] = 'S'; da[2] = 'W'; da[3] = 'N';
        if     (dd == 'E') dir = 0;
        else if(dd == 'S') dir = 1;
        else if(dd == 'W') dir = 2;
        else               dir = 3;
    }
    short xp;
    short yp;
    short dir;
    bool dead;
    char da[4];
    void turn(char d, int y)
    {
        if(d == 'L') dir = (dir + 4 - y % 4)  % 4;
        else         dir = (dir + y % 4)  % 4;
    }
    void go(int y)
    {
        while(y--)
        {
            if(dir == 0)
            {
                if(xp == c)
                {
                    cout<<"Robot "<<x<<" crashes into the wall"<<endl;
                    dead= 1;
                    break;
                }
                else
                {
                    if(g[xp + 1][yp] == 0)
                    {
                        xp ++;
                        g[xp][yp] = x;
                        g[xp - 1][yp] = 0;
                    }
                    else
                    {
                        cout<<"Robot "<<x<<" crashes into robot "<<g[xp + 1][yp]<<endl;
                        dead= 1;
                        break;
                    }
                }
            }
            else if(dir == 1)
            {
                if(yp == 1)
                {
                    cout<<"Robot "<<x<<" crashes into the wall"<<endl;
                    dead= 1;
                    break;
                }
                else
                {
                    if(g[xp][yp - 1] == 0)
                    {
                        yp --;
                        g[xp][yp] = x;
                        g[xp][yp + 1] = 0;
                    }
                    else
                    {
                        cout<<"Robot "<<x<<" crashes into robot "<<g[xp][yp - 1]<<endl;
                        dead= 1;
                        break;
                    }
                }
            }
            else if(dir == 2)
            {
                if(xp == 1)
                {
                    cout<<"Robot "<<x<<" crashes into the wall"<<endl;
                    dead= 1;
                    break;
                }
                else
                {
                    if(g[xp - 1][yp] == 0)
                    {
                        xp --;
                        g[xp][yp] = x;
                        g[xp + 1][yp] = 0;
                    }
                    else
                    {
                        cout<<"Robot "<<x<<" crashes into robot "<<g[xp - 1][yp]<<endl;
                        dead= 1;
                        break;
                    }
                }
            }
            else
            {
                if(yp == r)
                {
                    cout<<"Robot "<<x<<" crashes into the wall"<<endl;
                    dead= 1;
                    break;
                }
                else
                {
                    if(g[xp][yp + 1] == 0)
                    {
                        yp ++;
                        g[xp][yp] = x;
                        g[xp][yp - 1] = 0;
                    }
                    else
                    {
                        cout<<"Robot "<<x<<" crashes into robot "<<g[xp][yp + 1]<<endl;
                        dead= 1;
                        break;
                    }
                }
            }
        }
    }
};

int main()
{   
    cin>>kase;
    while(kase--)
    {
        cin>>c>>r>>n>>m;
        for(i = 1; i <= c; i ++) for(x = 1; x <= r; x++) g[i][x] = 0;
        vector<robot> vr;
        vr.push_back(robot(0, 0, 0));
        for(i = 1; i <= n; i++)
        {
            cin>>x>>y;
            cin>>d;
            vr.push_back(robot(x, y, d));
            g[x][y] = i;
        }
        for(i = 0; i < m; i++)
        {
            cin>>x>>d>>y; //id, move, repeat
            if(d != 'F')
            {
                vr[x].turn(d, y);
            }
            else
            {
                vr[x].go(y);
                if(vr[x].dead) break;
            }
        }
        if(i == m) cout<<"OK"<<endl;
        else for(; i < m - 1; i++) cin>>x>>d>>y;// eat
    }
    return 0;
}