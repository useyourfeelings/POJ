#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
int main()
{   
    int Case = 0, a, b;
    while(cin>>a>>b && a!= -1)
    {
        int rootnum = 0;
        bool ok = 0, die = 0;
        Case ++;
        map<int, int> iimap;
        map<int, int>::iterator itr;
        if((itr = iimap.find(a)) == iimap.end())
            iimap.insert(pair<int, int> (a, 0));
        if((itr = iimap.find(b)) == iimap.end())
            iimap.insert(pair<int, int> (b, 1));
        else ++(itr -> second);
        while(cin>>a>>b && a !=0 && b != 0)
        {
            if((itr = iimap.find(a)) == iimap.end())
                iimap.insert(pair<int, int> (a, 0));
            if((itr = iimap.find(b)) == iimap.end())
                iimap.insert(pair<int, int> (b, 1));
            else if(++(itr -> second) > 1){ die = 1; break;}
        }
        if(die) while(cin>>a>>b && a != 0 && b != 0);
        else
        {
            for(itr = iimap.begin(); itr != iimap.end(); ++itr)
            {
                if(itr -> second == 1) continue;
                if(++rootnum > 1) break;
            }
        }
        if(rootnum == 1) ok = 1;
        (ok) ? cout<<"Case "<<Case<<" is a tree."<<endl
             : cout<<"Case "<<Case<<" is not a tree."<<endl;
    }
    return 0;
}