#include<iostream>
#include<map>
#include<string>
using namespace std;

char x[11];
char y[11];

int main()
{
    int odd = 0;
    map<string, int> thing;
    map<string, int>::iterator itr;
    while(scanf("%s%s", &x, &y) != EOF)
    {
        itr = thing.find(x);
        if(itr == thing.end())
        {
            thing.insert(make_pair(x, 1));
            ++ odd;
        }
        else
        {
            if((++ (itr -> second)) % 2 == 0) -- odd;
            else ++ odd;
        }
        
        itr = thing.find(y);
        if(itr == thing.end())
        {
            thing.insert(make_pair(y, 1));
            ++ odd;
        }
        else
        {
            if((++ (itr -> second)) % 2 == 0) -- odd;
            else ++ odd;
        }
    }
    if(odd > 2) printf("Impossible\n");
    else printf("Possible\n");
    system("pause");
    return 0;
}