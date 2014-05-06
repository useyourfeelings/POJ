#include<iostream>
#include<map>
using namespace std;

class node
{
    public:
        node(int r):remain(r){}
        int remain;
        map<char, node> nodes;
};

char buff[1000][21];
node head(0);
map<char, node>::iterator itr, itr2;

int main()
{
    head.nodes.insert(make_pair('a', node(0)));
    int i, j, t, n = 0;
    while(scanf("%s", buff[n]) != EOF)
    {
        itr = head.nodes.begin();
        for(i = 0; i < strlen(buff[n]); ++ i)
        {
            itr2 = itr;
            itr = (itr2 -> second).nodes.find(buff[n][i]);
            if(itr == (itr2 -> second).nodes.end()) // not found
            {
                if(strlen(buff[n]) > i + 1) t = 1;
                else t = 0;
                itr = (itr2 -> second).nodes.insert(make_pair(buff[n][i], node(t))).first;
            }
            else // found
                if(strlen(buff[n]) > i + 1) ++ (itr -> second.remain);
        }
        
        ++ n;
    }
    for(i = 0; i < n; ++ i)
    {
        printf("%s ", buff[i]);
        itr = head.nodes.begin();
        for(j = 0; j < strlen(buff[i]); ++ j)
        {
            itr = (itr -> second).nodes.find(buff[i][j]);
            {
                printf("%c", buff[i][j]);
                if((itr -> second).remain <= 1) break;
            }
        }
        printf("\n");
    }
    return 0;
}