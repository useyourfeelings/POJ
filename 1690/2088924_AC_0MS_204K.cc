#include<iostream>
#include<vector>
using namespace std;

char line[256];

void make(int m)
{
    vector<int> stack;
    int i, s, total;
    for(i = 0; i < m; ++ i)
    {
        if(line[i] == '(') stack.push_back(i);
        else if(line[i] == ')')
        {
            total = 0;
            for(s = stack.back() - 1; s >= 0; -- s)
            {
                if(line[s] == '-')
                {
                    total = -2;
                    break;
                }
                else if(line[s] == '+' || line[s] == '(')
                {
                    line[stack.back()] = ' ';
                    line[i] = ' ';
                    total = -1;
                    break;
                }
            }
            if(total == -1 ) // done
            {
                //stack.pop_back();
            }
            else if(s < 0)
            {
                line[stack.back()] = ' ';
                line[i] = ' ';
            }
            else
            {
                total = 0;
                for(s = stack.back() + 1; s < i; ++ s)
                    if('A' <= line[s] && line[s] <= 'Z') ++ total;
                if(total <= 1)
                {
                    line[stack.back()] = ' ';
                    line[i] = ' ';
                }
            }
            stack.pop_back();
        }
    }
}

int main()
{
    int M, i, len;
    scanf("%d", &M);
    gets(line);
    while(M --)
    {
        gets(line);
        len = strlen(line);
        make(len);
        for(i = 0; i < len; ++ i)
            if(line[i] != ' ') printf("%c", line[i]);
        printf("\n");
    }
    system("pause");
    return 0;
}