#include<iostream>
using namespace std;

char sum[105];
char add[105];
char temp[105];

int main()
{   
    int i, j, end;
    cin>>temp;
    for(i = strlen(temp) - 1, j = 0; i >= 0; --i, ++j)
        sum[j] = temp[i];
    for(; j < 105; j++) sum[j] = '0';
    
    while(cin>>temp && !(temp[0] == '0' && strlen(temp) == 1))
    {
        end = 0;
        while(temp[end] == '0') ++ end;
        for(i = strlen(temp) - 1, j = 0; i >= end; --i, ++j)
            add[j] = temp[i];        
        for(i = 0; i < strlen(add); i++)
        {
            sum[i] += add[i] - 48;
            if(sum[i] > '9')
            {
                sum[i + 1] += 1;
                sum[i] -= 10;
            }
        }
        while(sum[i] > '9')
        {
            sum[i + 1] += 1;
            sum[i] -= 10;
        }
    }
    i = 104;
    while(sum[i] == '0') -- i;
    for(; i >= 0; i--) cout<<sum[i];
    cout<<endl;
    return 0;
}