#include<iostream>
#include<vector>
using namespace std;
int main()
{    
    int parent[10001], Case, nn, a, b, answer;
    cin>>Case;
    while(Case > 0)
    {
        cin>>nn;
        for(a = 1; a <= nn; a++) parent[a] = 0;
        while(nn > 1)
        {
            cin>>a>>b;
            parent[b] = a;
            nn --;
        }
        cin>>a>>b;
        vector<int> va(1, a), vb(1, b);
        while(1)
        {
            if(a != 0)
            {
                if(parent[va.back()] == 0) a = 0;
                else
                {
                    va.push_back(parent[va.back()]);
                    if(find(vb.begin(), vb.end(), va.back()) != vb.end())
                    {
                        answer = va.back();
                        break;
                    }
                }
            }
            if(b != 0)
            {
                if(parent[vb.back()] == 0) b = 0;
                else
                {
                    vb.push_back(parent[vb.back()]);
                    if(find(va.begin(), va.end(), vb.back()) != va.end())
                    {
                        answer = vb.back();
                        break;
                    }
                }
            }
        }
        cout<<answer<<endl;
        Case--;
    }
    return 0;
}