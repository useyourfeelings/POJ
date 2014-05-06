#include<iostream>
#include<set>
#include<string>
#include<vector>
using namespace std;

int Ca, Cb, N;
set<int> BeenThere;
vector<string> step;

bool make(int a, int b)
{
    if(a == N || b == N)
    {
        step.push_back("success");
        return 1;
    }
    if(BeenThere.find(a * 10000 + b) == BeenThere.end())
    {
        BeenThere.insert(a * 10000 + b);
        if(a != Ca)
        {
            if(make(Ca, b))
            {
                step.push_back("fill A");
                return 1;
            }
        }
        if(b != Cb)
        {
            if(make(a, Cb))
            {
                step.push_back("fill B");
                return 1;
            }
        }
        if(a != 0)
        {
            if(make(0, b))
            {
                step.push_back("empty A");
                return 1;
            }
        }
        if(b != 0)
        {
            if(make(a, 0))
            {
                step.push_back("empty B");
                return 1;
            }
        }
        if(a != 0 && b != Cb)
        {
            int t = min(a, Cb - b);
            if(make(a - t, b + t))
            {
                step.push_back("pour A B");
                return 1;
            }
        }
        if(b != 0 && a!= Ca)
        {
            int t = min(b, Ca - a);
            if(make(a + t, b - t))
            {
                step.push_back("pour B A");
                return 1;
            }
        }
        return 0;
    }
    else return 0;
}

int main()
{
    while(scanf("%d", &Ca) != EOF)
    {
        scanf("%d%d", &Cb, &N);
        BeenThere.clear();
        step.clear();
        make(0, 0);
        for(N = step.size() - 1; N >= 0; -- N) cout<<step[N]<<"\n";
    }
    return 0;
}