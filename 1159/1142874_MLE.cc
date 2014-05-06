#include<iostream>
using namespace std;
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
    int s, t;
    while(cin>>s)
    {
        char* a = new char[s];
        cin>>a;
        char* b = new char[s];
        for(int k = 0; k < s; k++)
            b[k] = a[s - 1 - k];
        int* c = new int[s * s];
        for(int k = 0; k < s * s; k++) c[k] = -1;
        t = fun(a, b, c, s - 1, s - 1, s);
        cout<<(s - t)<<endl;
        delete a;
        delete b;
        delete c;
    }
    return 0;
}