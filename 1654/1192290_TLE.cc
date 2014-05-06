#include<iostream>
using namespace std;
int main()
{   
    int Case;
    float area, x, y;
    char dir;
    cin>>Case;
    while(Case--)
    {
        area = 0; x = 0; y = 0;
        while(cin>>dir && dir != '5')
        {
            switch(dir)
            {
                case '1' :
                    area += x * (y - 1) - y * (x - 1);
                    x --; y --;                            break;
                case '2' :
                    area += x * (y - 1) - y * x;
                    y --;                                  break;
                case '3' :
                    area += x * (y - 1) - y * (x + 1);
                    x ++; y --;                            break;
                case '4' :
                    area += x * y - y * (x - 1);
                    x --;                                  break;
                case '6' :
                    area += x * y - y * (x + 1);
                    x ++;                                  break;
                case '7' :
                    area += x * (y + 1) - y * (x - 1);
                    x --; y ++;                            break;
                case '8' :
                    area += x * (y + 1) - y * x;
                    y ++;                                  break;
                case '9' :
                    area += x * (y + 1) - y * (x + 1);
                    x ++; y ++;                            break;
            }
        }
        area < 0 ? cout<<-area / 2<<endl
                 : cout<<area / 2<<endl;
    }
    return 0;
}