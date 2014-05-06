#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int test, n, i, k, f1, f2, result;
    string word, sentence, temp;
    string::iterator start, end;
    map<string, int>::iterator itr;
    cin>>test;
    for(k = 1; k <= test; ++ k)
    {
        map<string, int> dic;
        cin>>n;
        for(i = 0; i < n; ++ i)
        {
            cin>>word;
            if(word.length() > 3)
            {
                start = word.begin();
                end = word.end();
                ++ start;
                -- end;
                sort(start, end);
            }
            if((itr = dic.find(word)) == dic.end())
                dic.insert(make_pair(word, 1));
            else ++ (itr -> second);
        }
        printf("Scenario #%d:\n", k);
        cin>>n;
        getline(cin, sentence);
        for(i = 0; i < n; ++ i)
        {
            result = 1;
            getline(cin, sentence);
            sentence.append(" ");
            for(f1 = f2 = 0; f2 < sentence.length(); ++ f2)
            {
                if(sentence[f2] == ' ')
                {
                    temp = sentence.substr(f1, f2 - f1);
                    if(temp.length() > 3)
                    {
                        start = temp.begin();
                        end = temp.end();
                        ++ start;
                        -- end;
                        sort(start, end);
                    }
                    if((itr = dic.find(temp)) != dic.end())
                        result *= itr -> second;
                    else
                    {
                        result = 0;
                        break;
                    }
                    f1 = f2 + 1;
                    if(sentence[f1] == ' ') break;
                }
            }
            printf("%d\n", result);
        }
        printf("\n);
    }
    return 0;
}
