#include<iostream>
char a[200];
char b[200];
char c[400];
bool fun(int ai, int bi, int ci)
{
    for(;;)
    {
        if(ci < 0) return true;
        if(ai < 0 && bi >= 0)
        {
            if(c[ci] == b[bi])
            {
                ci --;
                bi --;
                continue;
            }
            return false;
        }
        if(ai >= 0 && bi < 0)
        {
            if(c[ci] == a[ai])
            {
                ci --;
                ai --;
                continue;
            }
            return false;
        }
        if(a[ai] == c[ci])
        {
            ci --;
            ai --;
            continue;
        }
        else if(b[bi] == c[ci])
        {
            ci --;
            bi --;
            continue;
        }
        else return false;
    }
}
int main()
{
    int n;
    std::cin>>n;
    for(int i = 1; i <= n; i++)
    {
        std::cin>>a>>b>>c;
        if(fun(strlen(a) - 1, strlen(b) - 1, strlen(c) - 1))
        {
            std::cout<<"Data set "<<i<<": yes"<<std::endl;
            continue;
        }
        std::cout<<"Data set "<<i<<": no"<<std::endl;
    }
    return 0;
}