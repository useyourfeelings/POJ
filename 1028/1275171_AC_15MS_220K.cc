#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main()
{
    string command;
    string url;
    string current("http://www.acm.org/");
    vector<string> f;
    vector<string> b;
    while(cin>>command)
    {
        if(command == "FORWARD")
        {
            if(f.empty())
            {
                cout<<"Ignored"<<endl;
                continue;
            }
            b.push_back(current);
            current = f.back();
            cout<<current<<endl;
            f.pop_back();
        }
        else if(command == "BACK")
        {
            if(b.empty())
            {
                cout<<"Ignored"<<endl;
                continue;
            }
            f.push_back(current);
            current = b.back();
            cout<<current<<endl;
            b.pop_back();
        }
        else if(command == "VISIT")
        {
            cin>>url;
            cout<<url<<endl;
            b.push_back(current);
            current = url;
            f.clear();
        }
        else break;
    }
    return 0;
}