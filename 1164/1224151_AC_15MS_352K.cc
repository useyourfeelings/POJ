#include<iostream>
#include<list>
using namespace std;
struct grid
{
    grid():done(0){}
    bool done;
    list<char> cango;
};
grid c[50][50];
int s;
void fun(int i, int j)
{
    s++;
    c[i][j].done = 1;
    while(!c[i][j].cango.empty())
    {
        switch(c[i][j].cango.front())
        {
            case 'w' :
                if(!c[i][j - 1].done)
                fun(i    , j - 1);                  break;
            case 'n' :
                if(!c[i - 1][j].done)
                fun(i - 1, j    );                  break;
            case 'e' :
                if(!c[i][j + 1].done)
                fun(i    , j + 1);                  break;
            case 's' :
                if(!c[i + 1][j].done)
                fun(i + 1, j    );                  break;
        }
        c[i][j].cango.pop_front();
    }
}
int main()
{     
    int m, n, num, max = 0, i, j;
    cin>>m>>n;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin>>s;
            switch(s)
            {
                case 0:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('n');
                    c[i][j].cango.push_back('e');
                    c[i][j].cango.push_back('s');        break;
                case 1:
                    c[i][j].cango.push_back('n');
                    c[i][j].cango.push_back('e');
                    c[i][j].cango.push_back('s');        break;
                case 2:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('e');
                    c[i][j].cango.push_back('s');        break;
                case 4:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('n');
                    c[i][j].cango.push_back('s');        break;
                case 8:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('n');
                    c[i][j].cango.push_back('e');        break;
                case 3:
                    c[i][j].cango.push_back('e');
                    c[i][j].cango.push_back('s');        break;
                case 5:
                    c[i][j].cango.push_back('n');
                    c[i][j].cango.push_back('s');        break;
                case 9:
                    c[i][j].cango.push_back('n');
                    c[i][j].cango.push_back('e');        break;
                case 6:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('s');        break;
                case 10:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('e');        break;
                case 12:
                    c[i][j].cango.push_back('w');
                    c[i][j].cango.push_back('n');        break;
                case 7:
                    c[i][j].cango.push_back('s');        break;
                case 13:
                    c[i][j].cango.push_back('n');        break;
                case 11:
                    c[i][j].cango.push_back('e');        break;
                case 14:
                    c[i][j].cango.push_back('w');        break;
                case 15:
                                                         break;
            }
        }
    }
    num = 0;
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(!c[i][j].done)
            {
                num ++;
                s = 0;
                fun(i, j);
                if(s > max) max = s;                
            }
        }
    }
    cout<<num<<endl<<max<<endl;
    return 0;
}