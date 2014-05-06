#include<iostream>
using namespace std;
short man[1000];
short elapsed;
int main()
{   
    short t, n, i;
    scanf("%d", &t);
    while(t--)
    {
        elapsed = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++) scanf("%d", &man[i]);
        for(;;)
        {
            if(n == 1)
            {
                elapsed += man[0];
                break;
            }
            else if(n == 2)
            {
                elapsed += man[1];
                break;
            }
            else if(n == 3)
            {
                elapsed += man[1] + man[0] + man[2];
                break;
            }
            else 
            {
                if(2 * man[1] >= man[0] + man[n - 2])
                {
                    elapsed += man[n - 1] + man[0];
                    n --;
                }
                else
                {
                    elapsed += man[0] + man[1] + man[n - 1] + man[1];
                    n -= 2;
                }
            }
        }
        cout<<elapsed<<endl;
    }
    return 0;
}