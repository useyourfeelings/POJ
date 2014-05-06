#include<iostream>
using namespace std;
int main()
{   
    int Case;
    long long area;
    int x, y;
    char dir;
    cin>>Case;
    while(Case--)
    {
        area = 0; x = 0; y = 0;
        for(;;)
        {
            scanf("%c", &dir);
            if(dir == '5') break;
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
        if(area < 0) area = -area;
        cout<<area / 2;
        if(area % 2 != 0) cout<<".5";
        cout<<endl;
    }
    return 0;
}