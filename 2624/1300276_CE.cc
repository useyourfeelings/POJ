#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    cout<<setiosflags(ios::fixed)<<setprecision(3);
    double x1, x2, x3, y1, y2, y3, t1, t2, x, y;
    while(cin>>x1>>y1>>x2>>y2>>t1>>t2>>x3>>y3
    {
        if(t1 == x1 && t2 == y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }
        else if(x3 == x1 && y3 == y1)
        {
            swap(x1, x2);
            swap(y1, y2);
            swap(t1, x3);
            swap(t2, y3);
        }
        else if(x3 == x2 && y3 == y2)
        {
            swap(t1, x3);
            swap(t2, y3);
        }
        cout<<x3 + x1 - x2<<" "<<y3 + y1 - y2<<endl;
    }
    return 0;
}