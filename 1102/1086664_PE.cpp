//   acm   LC-Display          03_21_2006

#include<iostream>

using namespace std;

//////////////////////////////////////////////////////

static bool SevenSegment [10][7] = {
                      // 0  1  2  3  4  5  6
                         1, 1, 1, 0, 1, 1, 1,     // 0
                         0, 0, 1, 0, 0, 1, 0,     // 1
                         1, 0, 1, 1, 1, 0, 1,     // 2
                         1, 0, 1, 1, 0, 1, 1,     // 3
                         0, 1, 1, 1, 0, 1, 0,     // 4
                         1, 1, 0, 1, 0, 1, 1,     // 5
                         1, 1, 0, 1, 1, 1, 1,     // 6
                         1, 0, 1, 0, 0, 1, 0,     // 7
                         1, 1, 1, 1, 1, 1, 1,     // 8
                         1, 1, 1, 1, 0, 1, 1 } ;  // 9

//////////////////////////////////////////////////////

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
    
    bool *outputarray[8];         // every pointer points to an array
    int i;
    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////
    
    for(i = StartIndex; i < SIZE; i ++)               //   initialize
    {
        outputarray[i] = new bool[(s + 2) * (2 * s + 3)];
        for(int j = 0; j < (s + 2) * (2 * s + 3); j++)
        {
            outputarray[i][j] = 0;
        }
        
        int num = inputarray[i];
        
        if(SevenSegment[num][0])
        for(int j = 1; j <= s; j++)
        {
            outputarray[i][j] = 1;
        }
        
        if(SevenSegment[num][1])
        for(int j = s + 2; j <= s * (s + 2); j += (s + 2))
        {
            outputarray[i][j] = 1;
        }
        
        if(SevenSegment[num][2])
        for(int j = s + s + 3; j <= s * (s + 2) + s + 3; j += (s + 2))
        {
            outputarray[i][j] = 1;
        }
        
        if(SevenSegment[num][3])
        for(int j = (s + 2) * (s + 1) + 1; j <= (s + 2) * (s + 2) - 2; j++)
        {
            outputarray[i][j] = 1;
        }
        
        if(SevenSegment[num][4])
        for(int j = (s + 2) * (s + 2); j <= (s + 2) * (s + 2) + (s - 1) * (s + 2); j+= (s+2))
        {
            outputarray[i][j] = 1;
        }
        
        if(SevenSegment[num][5])
        for(int j = (s + 2) * (s + 2) + s + 1;
                           j <= (s + 2) * (s + 2) + s + 1 + (s - 1) * (s + 2);     j+= (s+2))
        {
            outputarray[i][j] = 1;
        }
        
        if(SevenSegment[num][6])
        for(int j = (s + 2) * (2 * s + 2) + 1; j <= (s + 2) * (2 * s + 2) + s; j++)
        {
            outputarray[i][j] = 1;
        }
    }
    
    //////////////////////////////////////////
    //////////////////////////////////////////
    //////////////////////////////////////////       display
    
    for(i = 0; i <= 2 * s + 2; i ++)
    {
        for(int j = StartIndex; j < SIZE; j ++)
        {
            for(int k = 0; k < s + 2; k ++)
            {
                if(outputarray[j][i * (s + 2) + k])
                {
                    if(i == 0 || i == s + 1 || i == (2 * s + 2))
                    cout<<"-";
                    
                    else
                    cout<<"|";
                }
                
                else
                cout<<" ";
            }
            cout<<" ";            
        }
        cout<<endl;        
    }
    
    for(i = StartIndex; i < SIZE; i++)
    delete outputarray[i];
}

////////////////////////////////////////
////////////////////////////////////////
////////////////////////////////////////

int main()
{
    int s;
    int n;

    while(cin>>s>>n)
    {
        if(s == 0 && n == 0)
        break;
        
        make(s, n);
    }
    
    cout<<endl<<endl;
    system("pause");
    return 0;
}
