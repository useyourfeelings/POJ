#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
struct coin
{
    int p; int w;
    coin(void){}
    coin(int _p, int _w):p(_p),w(_w){}
};
bool operator >(const coin& c1, const coin& c2)
{
    return (double(c1.w) / double(c1.p)) > (double(c2.w) / double(c2.p));
}
int make(int x, vector<coin> &vc, vector<int> &record, vector<coin>::iterator start)
{
    if(x == 0) return 0;
    if(record[x] == -1) return -1;
    if(record[x] != 0) return record[x];
    int min = 500000001, t, count = 0;
    for(vector<coin>::iterator itr = start; itr != vc.end(); itr++ )
    {
        if((itr -> w) <= x)
        {
            if((t = make(x - (itr -> w), vc, record, itr)) != -1)
            {
                count++;
                t += (itr -> p);
                if(t < min) min = t;
            }
        }
    }
    if(count == 0)
    {
        record[x] = -1;
        return -1;
    }
    record[x] = min;
    return min;
}    
int main()
{   
    int Case, e, f, num, p, w, answer;
    cin>>Case;
    for(; Case > 0; Case--)
    {
        cin>>e>>f>>num;
        vector<coin> vc(num);
        vector<int> record(f - e + 1, 0);
        for(int i = 0; i < num; i++)
        {
            cin>>p>>w;
            vc[i] = coin(p, w);
        }
        sort(vc.begin(), vc.end(), greater<coin>());
        if((answer = make(f - e, vc, record, vc.begin())) != -1)
            cout<<"The minimum amount of money in the piggy-bank is "
                <<answer<<endl;
        else
            cout<<"This is impossible."<<endl;
    }     
    return 0;
}
