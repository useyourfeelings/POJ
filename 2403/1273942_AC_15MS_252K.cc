#include<iostream>
#include<map>
#include<cstring>
using namespace std;

int main()
{   
    string a;
    int m, n, salary;
    cin>>m>>n;
    map<string, int> cim;
    while(m--)
    {
        cin>>a>>salary;
        cim.insert(make_pair(a, salary));
    }
    while(n--)
    {
        salary = 0;
        while(cin>>a)
        {
            if(a[0] == '.')break;
            map<string, int>::iterator itr;
            if((itr = cim.find(a)) != cim.end())
                salary += itr -> second;
        }
        cout<<salary<<endl;
    }
    return 0;
}