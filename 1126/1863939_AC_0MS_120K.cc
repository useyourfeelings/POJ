#include<iostream>
using namespace std;

char text[257];
int index;

bool FindOne()
{
    ++ index;
    if('p' <= text[index] && text[index] <= 'z') return 1;
    else if(text[index] == 'N') return FindOne();
    else if(text[index] == 'C' || text[index] == 'D' ||
            text[index] == 'E' || text[index] == 'I')
    {
        if(FindOne()) return FindOne();
        else return 0;
    }
    else return 0;
}

int main()
{
    while(scanf("%s", &text) != EOF)
    {
        index = -1;
        if(FindOne())
        {
            if(text[index + 1] == '\0') printf("YES\n");
            else printf("NO\n");
        }
        else printf("NO\n");
    }
    return 0;
}