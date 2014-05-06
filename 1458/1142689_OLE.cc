#include<iostream>
using namespace std;
const int N = 500;
int fun(char* a, char* b, int* c, int i, int j, int X)
{
    if(i < 0 || j < 0) return 0;
    if(c[i * X + j] != -1) return c[i * X + j];
    if(a[i] == b[j])
    {
         c[i * X + j] = (fun(a, b, c, i - 1, j - 1, X) + 1);
         return c[i * X + j];
    }
    c[i * X + j] = max(fun(a, b, c, i, j - 1, X), fun(a, b, c, i - 1, j, X));
    return c[i * X + j];
}
int main()
{
    char a[N], b[N];
    while(1)
    {
        cin>>a>>b;
        int la = strlen(a), lb = strlen(b);
        int* c = new int[la * lb];
        for(int k = 0; k < la * lb; k++) c[k] = -1;
        cout<<fun(a, b, c, la - 1, lb - 1, lb)<<endl;
        delete c;
    }
    return 0;
}