//  acm 1102 LC-Display      03_22_2006

#include<iostream>
using namespace std;
static bool SevenSegment [10][7] = {
1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1,
1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 0, 1, 1 } ;

const int SIZE = 8;

int ITOARRAY(int s, int a[], int base)
{
    int b = base;

    for(int i = SIZE -1; i >= 0; i--)
    {
        a[i] = s % b  / (b / base);

        if(s / b == 0)
        return i;

        b *= base;
    }
}

void make(int s, int n)
{
    int inputarray[SIZE];
    int StartIndex = ITOARRAY(n, inputarray, 10);

    int i, j, k;

    for(j = StartIndex; j < SIZE; j++)
    {
        cout<<" ";

        for(k = 0; k < s; k++)
        {
            if(SevenSegment[inputarray[j]][0]) cout<<"-";
            else cout<<" ";
        }
        cout<<" ";

        if(j != SIZE -1) cout<<" ";
    }
    cout<<endl;
    
    for(i = 0; i < s; i++)
    {
        for(j = StartIndex; j < SIZE; j++)
        {
            if(SevenSegment[inputarray[j]][1]) cout<<"|";
            else cout<<" ";
            
            for(k = 0; k < s; k++) cout<<" ";
            
            if(SevenSegment[inputarray[j]][2]) cout<<"|";
            else cout<<" ";

            if(j != SIZE -1) cout<<" ";
        }
        cout<<endl;
    }

    for(j = StartIndex; j < SIZE; j++)
    {
        cout<<" ";

        for(k = 0; k < s; k++)
        {
            if(SevenSegment[inputarray[j]][3]) cout<<"-";
            else cout<<" ";
        }
        cout<<" ";

        if(j != SIZE -1) cout<<" ";
    }
    cout<<endl;

    for(i = 0; i < s; i++)
    {
        for(j = StartIndex; j < SIZE; j++)
        {
            if(SevenSegment[inputarray[j]][4]) cout<<"|";
            else cout<<" ";

            for(k = 0; k < s; k++) cout<<" ";

            if(SevenSegment[inputarray[j]][5]) cout<<"|";
            else cout<<" ";

            if(j != SIZE -1) cout<<" ";
        }
        cout<<endl;
    }

    for(j = StartIndex; j < SIZE; j++)
    {
        cout<<" ";

        for(k = 0; k < s; k++)
        {
            if(SevenSegment[inputarray[j]][6]) cout<<"-";
            else cout<<" ";
        }
        cout<<" ";

        if(j != SIZE -1) cout<<" ";
    }
}

int main()
{
    int s;
    int n;
    while(cin>>s>>n)
    {
        if(s == 0 && n == 0)
        break;

        make(s, n);
        cout<<endl<<endl;
    }
    system("pause");
    return 0;
}