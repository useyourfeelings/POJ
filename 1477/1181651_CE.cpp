#include<iostream>
using namespace std;
int wall[50];
int main()
{
    int num, sum, av, Case = 1;
    while(cin>>num && num != 0)
    {
        sum = 0;
        for(int i = 0; i < num; i++)
        {
            cin>>wall[i];
            sum += wall[i];
        }
        av = sum / num;
        sum = 0;
        for(int i = 0; i < num; i++)
            if(wall[i] < av) sum += (av - wall[i]);
        cout<<"Set #"<<Case++<<endl
            <<"The minimum number of moves is "<<sum<<"."<<endl<<endl;
    }
    return 0;
}