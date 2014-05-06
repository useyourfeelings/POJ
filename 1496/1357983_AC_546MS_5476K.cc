#include<iostream>
#include<map>
#include<string>
using namespace std;

char word[5] = {0, 0, 0, 0, 0};

int main()
{
    map<string, int> dic;
    char a, b, c, d, e;
    int index = 1;
    for(a = 'a'; a <= 'z'; ++ a, ++ index)
    {
        word[0] = a;
        dic.insert(make_pair(word, index));
    }
    for(a = 'a'; a <= 'y'; ++ a)
    {
        word[0] = a;
        for(b = a + 1; b <= 'z'; ++ b, ++ index)
        {
            word[1] = b;
            dic.insert(make_pair(word, index));
        }
    }
    for(a = 'a'; a <= 'x'; ++ a)
    {
        word[0] = a;
        for(b = a + 1; b <= 'y'; ++ b)
        {
            word[1] = b;
            for(c = b + 1; c <= 'z'; ++ c, ++ index)
            {
                word[2] = c;
                dic.insert(make_pair(word, index));
            }
        }
    }
    for(a = 'a'; a <= 'w'; ++ a)
    {
        word[0] = a;
        for(b = a + 1; b <= 'x'; ++ b)
        {
            word[1] = b;
            for(c = b + 1; c <= 'y'; ++ c)
            {
                word[2] = c;
                for(d = c + 1; d <= 'z'; ++ d, ++ index)
                {
                    word[3] = d;
                    dic.insert(make_pair(word, index));
                }
            }
        }
    }
    for(a = 'a'; a <= 'v'; ++ a)
    {
        word[0] = a;
        for(b = a + 1; b <= 'w'; ++ b)
        {
            word[1] = b;
            for(c = b + 1; c <= 'x'; ++ c)
            {
                word[2] = c;
                for(d = c + 1; d <= 'y'; ++ d)
                {
                    word[3] = d;
                    for(e = d + 1; e <= 'z'; ++ e, ++ index)
                    {
                        word[4] = e;
                        dic.insert(make_pair(word, index));
                    }
                }
            }
        }
    }
    map<string, int>::iterator itr;
    while(gets(word))
    {
        if((itr = dic.find(word)) != dic.end())
            cout<<dic.find(word) -> second<<endl;
        else printf("0\n");
    }
    return 0;
}
