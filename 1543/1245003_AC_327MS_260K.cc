#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct ct
{
    ct(float aa, float bb, float cc, float dd):a(aa),b(bb),c(cc),d(dd){}
    float a;
    float b;
    float c;
    float d;
};
int main()
{   
    float a, b, c, d, n;
    vector<ct> vct;
    for(a = 1; a <= 100; a++)
    {
        for(b = 2; b < a; b++)
        {
            for(c = b; c < a; c++)
            {
                for(d = c; d < a; d++)
                {
                    if(pow(a, 3) == pow(b, 3) + pow(c, 3) + pow(d, 3))
                        vct.push_back(ct(a, b, c, d));
                }
            }
        }
    }
    cin>>n;
    int s = vct.size();
    for(int i = 0; i < s; i++)
    {
        if(vct[i].a > n) break;
        cout<<"Cube = "<<vct[i].a<<", Triple = ("
            <<vct[i].b<<","<<vct[i].c<<","<<vct[i].d<<")"<<endl;
    }
    return 0;
}