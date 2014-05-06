#include<iostream>
using namespace std;
int main()
{   
    int move[10], i;
    memset(move, 0, sizeof(move));
    char lock[10], lable[10];
    cin>>lock;
    int size = strlen(lock);
    while(cin>>lable)
    {
        for(i = 0; i < size; i++) move[i] += int(lable[i]) - 48;
    }
    for(i = 0; i < size; i++)
    {
        cout<<(int(lock[i]) - 48 + move[i]) % 10;
    }
    return 0;
}