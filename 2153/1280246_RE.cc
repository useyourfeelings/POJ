#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string name;
string lm(" Li Ming");

int main()
{   
    int n, i, j, k, t, s, ls;
    cin>>n;
    getline(cin, name, '\n');
    for(i = 0; i < n; i++) getline(cin, name, '\n');
    cin>>t;
    for(i = 0; i < t; i++)
    {
        vector<int> score(n);
        for(j = 0; j < n; j++)
        {
            scanf("%d", s);
            score[j] = s;
            getline(cin, name, '\n');
            if(name == lm) ls = s;
        }
        sort(score.begin(), score.end());
        for(k = score.size() - 1; k >= 0; k --)
        {
            if(ls == score[k])
            {
                cout<<n - k<<endl;
                break;
            }
        }
    }
    return 0;
}