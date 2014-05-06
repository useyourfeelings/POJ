#include<iostream>
#include<map>
using namespace std;

class node
{
    public:
        node(int r):remain(r),end(0){}
        int remain;
        int end;
        map<char, node> nodes;
};

char buff[1000][21];
node head(0);
map<char, node>::iterator itr, itr2;

int main()
{
    head.nodes.insert(make_pair('a', node(0)));
    int i, j, t, len, n = 0;
    while(scanf("%s", buff[n]) != EOF)
    {
        itr = head.nodes.begin();
        len = strlen(buff[n]);
        for(i = 0; i < len; ++ i)
        {
            itr2 = itr;
            itr = (itr2 -> second).nodes.find(buff[n][i]);
            if(itr == (itr2 -> second).nodes.end()) // not found
            {
                if(strlen(buff[n]) > i + 1) t = 1;
                else t = 0;
                itr = (itr2 -> second).nodes.insert(make_pair(buff[n][i], node(t))).first;
            }
            else
                if(strlen(buff[n]) > i + 1) ++ (itr -> second.remain);
        }
        ++ itr -> second.end;
        ++ n;
    }
    for(i = 0; i < n; ++ i)
    {
        printf("%s ", buff[i]);
        itr = head.nodes.begin();
        len = strlen(buff[i]);
        for(j = 0; j < len; ++ j)
        {
            itr = (itr -> second).nodes.find(buff[i][j]);
            printf("%c", buff[i][j]);
            if(j == len - 1) break;
            if((itr -> second).remain <= 1 && (itr -> second).end == 0) break;
        }
        if(i < n - 1) printf("\n");
    }
    return 0;
}