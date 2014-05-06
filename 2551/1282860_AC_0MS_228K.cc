#include<iostream>
using namespace std;
int main()
{   
    int n, i, re;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1, re = 1; ; )
        {
            for(; ; i ++, re = re * 10 + 1)
                 if(re / n >= 1) break;
            if((re = re % n) == 0) break;
        }
        cout<<i<<endl;
    }
    return 0;
}