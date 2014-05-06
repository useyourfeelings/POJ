#include<iostream>
using namespace std;
float x[2], y[2];    // start : 0, 0
int main()
{   
    int Case;
    float area;
    char dir;
    cin>>Case;
    while(Case--)
    {
        area = 0;
        x[0] = 0; y[0] = 0;
        while(cin>>dir && dir != '5')
        {
            switch(dir)
            {
                case '1' : x[1] = x[0] -1; y[1] = y[0] -1; break;
                case '2' : x[1] = x[0]   ; y[1] = y[0] -1; break;
                case '3' : x[1] = x[0] +1; y[1] = y[0] -1; break;
                case '4' : x[1] = x[0] -1; y[1] = y[0]   ; break;
                case '6' : x[1] = x[0] +1; y[1] = y[0]   ; break;
                case '7' : x[1] = x[0] -1; y[1] = y[0] +1; break;
                case '8' : x[1] = x[0]   ; y[1] = y[0] +1; break;
                case '9' : x[1] = x[0] +1; y[1] = y[0] +1; break;
            }
            area += (x[0] * y[1] - y[0] * x[1]) / 2;
            x[0] = x[1]; y[0] = y[1];
        }
        area < 0 ? cout<<-area<<endl
                 : cout<<area<<endl;
    }
    return 0;
}