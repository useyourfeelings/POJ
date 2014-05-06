#include<iostream>
using namespace std;

int op[1000];
int reg[10];

int main()
{
    int pos = 0, step, a, b;
    bool halt = 0;
    memset(op, 0, sizeof(op));
    memset(reg, 0, sizeof(reg));
    while(scanf("%d", &op[pos]) != EOF) ++ pos;
    for(pos = step = 0;;)
    {
        ++ step;
        a = op[pos] % 100 / 10;
        b = op[pos] % 10;
        if(op[pos] / 100 == 0)
        {
            if(reg[b] != 0)
            {
                pos = reg[a];
                continue;
            }
        }
        switch(op[pos] / 100)
        {
            case 1:
                halt = true;
                break;
            case 2:
                reg[a] = b;
                break;
            case 3:
                reg[a] = (reg[a] + b) % 1000;
                break;
            case 4:
                reg[a] = (reg[a] * b) % 1000;
                break;
            case 5:
                reg[a] = reg[b];
                break;
            case 6:
                reg[a] = (reg[a] + reg[b]) % 1000;
                break;
            case 7:
                reg[a] = (reg[a] * reg[b]) % 1000;
                break;
            case 8:
                reg[a] = op[reg[b]];
                break;
            case 9:
                op[reg[b]] = reg[a];
                break;
        }
        ++ pos;
        if(halt) break;
    }
    printf("%d", step);
    return 0;
}