#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
char digit[7], buffer[8];
int main()
{
    int bfrom, bto, s, t, answer, i;
    while(cin>>digit>>bfrom>>bto)
    {
        t = 0;
        s = strlen(digit);
        for(i = 0 ; i < s; i ++) 
        {
            if(isalpha(digit[i])) digit[i] = digit[i] - 55;
            else                  digit[i] = digit[i] - 48;
        }
        for(i = 0 ; i < s; i ++)
        {
            t += int(pow(double(bfrom), s - 1 - i) * digit[i]);
        }
        for(i = 0; i < 8; i++)
        {
            if(i == 7) break;
            buffer[7 - i] = (t % bto > 9) ? t % bto + 55 : t % bto + 48;
            t /= bto;
            if(t == 0) break; 
        }
        if(i == 7) cout<<setw(7)<<setiosflags(ios::right)<<"ERROR"<<endl;
        else
        {
            for(t = 1; t < 8; t ++)
            {
                if(t >= 7 - i) cout<<buffer[t];
                else           cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
