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
                    area += (y--) - (x--);                 break;
                case '2' :
                    area += -x;                  y --;     break;
                case '3' :
                    area += -(x++) - (y--);                break;
                case '4' :
                    area += y;                   x --;     break;
                case '6' :
                    area += -y;                  x ++;     break;
                case '7' :
                    area += (x--) + (y++);                 break;
                case '8' :
                    area += x;                   y ++;     break;
                case '9' :
                    area += (x++) - (y++);                 break;
            }
        }
        area < 0 ? cout<<-area / 2<<endl
                 : cout<<area / 2<<endl;
    }
    return 0;
}