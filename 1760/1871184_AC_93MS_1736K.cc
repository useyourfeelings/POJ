#include<iostream>
#include<map>
#include<string>
using namespace std;

char path[82];

struct node
{
    node(){}
    map<string, node> child;
};

node head;
typedef map<string, node>::iterator mapitr;
mapitr currpos, tempitr;

void DisplayOneNode(const node *pn, int pad)
{
    map<string, node>::const_iterator mb = pn->child.begin();
    map<string, node>::const_iterator me = pn->child.end();
    int i;
    for(; mb != me; ++ mb)
    {
        for(i = 0; i < pad; ++ i) printf(" ");
        cout<<mb->first<<"\n";
        DisplayOneNode(&(mb->second), pad + 1);
    }
}

int main()
{
    int n, i, j;
    scanf("%d", &n);
    string name;
    while(n --)
    {
        scanf("%s", path);
        i = 0;
        for(j = 0; j < strlen(path); ++ j) if(path[j] == '\\') break;
        name.assign(path + i, path + j);
        if((currpos = head.child.find(name)) == head.child.end()) // not found
        {
            currpos = head.child.insert(make_pair(name, node())).first;
        }
        for(i = j + 1; i < strlen(path);)
        {
            for(j = i + 1; j < strlen(path); ++ j) if(path[j] == '\\') break;
            name.assign(path + i, path + j);
            if((tempitr = currpos->second.child.find(name)) ==
                                  currpos->second.child.end()) // not found
            {
                currpos = currpos->second.child.insert(make_pair(name, node())).first;
            }
            else
            {
                currpos = tempitr;
            }
            i = j + 1;
        }
    }
    DisplayOneNode(&head, 0);
    return 0;
}
