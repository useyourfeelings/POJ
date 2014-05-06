#include<iostream>
using namespace std;
int main()
{   
    double h, u, d, f, sum;
    int day;
    while(cin>>h>>u>>d>>f && h != 0)
    {
        f = f / 100 * u;
        sum = 0;
        for(day = 1;; day++)
        {
            sum += u;
            if(sum > h) break;
            sum -= d;
            if(sum < 0) break;
            u -= f;
            if(u < 0)
            {
                day += sum / d + 1;
                sum = -1;
                break;
            }
        }
        (sum < 0) ? cout<<"failure on day "<<day<<endl
                  : cout<<"success on day "<<day<<endl;
    }
    return 0;
}