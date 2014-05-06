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
    
    int i, j, k, num;
   
    for(j = StartIndex; j < SIZE; j++)
    {
        num = inputarray[j];
            
        cout<<" ";
            
        if(SevenSegment[num][0])           //   0
        for(k = 0; k < s; k++)
        cout<<"-";
            
        else
        for(k = 0; k < s; k++)
        cout<<" ";
        
        cout<<" ";
        
        if(j != SIZE -1)    
        cout<<" ";
    }
    
    cout<<endl;
    
    for(i = 0; i < s; i++)
    {
        for(j = StartIndex; j < SIZE; j++)
        {
            num = inputarray[j];
            if(SevenSegment[num][1]) cout<<"|";               //  1
            else cout<<" ";
            
            for(k = 0; k < s; k++) cout<<" ";
            
            if(SevenSegment[num][2]) cout<<"|";               //   2
            else cout<<" ";
            
            if(j != SIZE -1)    
            cout<<" ";
        }
        cout<<endl;
    }
    
    for(j = StartIndex; j < SIZE; j++)
    {
        num = inputarray[j];
            
        cout<<" ";
            
        if(SevenSegment[num][3])                              //   3
        for(k = 0; k < s; k++) cout<<"-";
            
        else
        for(k = 0; k < s; k++) cout<<" ";
        
        cout<<" ";        
        if(j != SIZE -1)    
        cout<<" ";
    }            
    
    cout<<endl;
    
    for(i = 0; i < s; i++)
    {
        for(j = StartIndex; j < SIZE; j++)
        {
            num = inputarray[j];
            if(SevenSegment[num][4]) cout<<"|";               //  4
            else cout<<" ";
            
            for(k = 0; k < s; k++) cout<<" ";
            
            if(SevenSegment[num][5]) cout<<"|";               //   5
            else cout<<" ";
            
            if(j != SIZE -1)    
            cout<<" ";
        }
        cout<<endl;
    }
            
    for(j = StartIndex; j < SIZE; j++)
    {
        num = inputarray[j];
            
        cout<<" ";
            
        if(SevenSegment[num][6])                              //   6
        for(k = 0; k < s; k++)
        cout<<"-";
            
        else
        for(k = 0; k < s; k++)
        cout<<" ";
        
        cout<<" ";        
        if(j != SIZE -1)    
        cout<<" ";
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
        cout<<endl;
    }
    system("pause");
    return 0;
}