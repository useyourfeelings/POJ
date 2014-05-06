#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.1415927;
const double area = 50; 

int cal(double r)
{
    double s = area;
    for(int i = 1; ; i ++)
    {
        if(r < sqrt(2 * s / PI))
        {
                       return i;
            }
            s += 50;
    }
}

int main()
{
    int size = 0;
    cin>>size;
    
    double x, y, r;
    
    for(int i = 1; i < size + 1; i++)
    {
        cin>>x>>y;
        r = sqrt(x * x + y * y);
        
        cout<<"Property "<<i<<": This property will begin eroding in year "
            <<cal(r)<<"."<<endl;
    }
    
    cout<<"END OF OUTPUT.";
       
    system("pause");
    return 0;
}