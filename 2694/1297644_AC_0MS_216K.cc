#include<iostream>
#include<algorithm>
using namespace std;

struct card
{
    char num;
    char suit;
};

bool comp(const card &a, const card &b)
{
    return a.num < b.num;
}

card p[5];

bool isOP()
{
    int t = 5;
    for(int i = 0; i < 4; ++ i)
       if(p[i].num == p[i + 1].num) -- t;
    if(t == 4) return 1;
    return 0;
}

bool isTP()
{
    int t = 5;
    for(int i = 0; i < 4; ++ i)
    {
        if(p[i].num == p[i + 1].num)
        {
            -- t;
            ++ i;
        }
    }
    if(t == 3) return 1;
    return 0;
}

bool isTOAK()
{
    if(p[0].num == p[1].num && p[1].num == p[2].num)
    {
        if(p[3].num != p[0].num && p[4].num != p[0].num &&
            p[3].num != p[4].num) return 1;
    }
    else if(p[1].num == p[2].num && p[2].num == p[3].num)
    {
        if(p[0].num != p[1].num && p[4].num != p[1].num &&
            p[0].num != p[4].num) return 1;
    }
    else if(p[2].num == p[3].num && p[3].num == p[4].num)
    {
        if(p[0].num != p[2].num && p[1].num != p[2].num &&
            p[0].num != p[1].num) return 1;
    }
    return 0;
}

bool isFH()
{
    if(p[0].num == p[1].num && p[1].num == p[2].num)
    {
        if(p[0].num != p[3].num && p[3].num == p[4].num) return 1;
    }
    else if(p[2].num == p[3].num && p[3].num == p[4].num)
    {
        if(p[0].num != p[3].num && p[0].num == p[1].num) return 1;
    }
    return 0;
}

bool isFOAK()
{
    if(p[0].num != p[1].num)
    {
        for(int i = 3; i >= 1; -- i)
            if(p[i].num != p[i + 1].num) return 0;
        return 1;
    }
    else if(p[3].num != p[4].num)
    {
        for(int i = 2; i >= 0; -- i)
            if(p[i].num != p[i + 1].num) return 0;
        return 1;
    }
    return 0;
}

bool isS()
{
    if(p[0].num == 49)
    {
        if(p[1].num == 50)
        {
            for(int i = 2; i < 5; ++ i)
                if(p[i].num - 1 != p[i - 1].num) return 0;
            return 1;
        }
        else if(p[1].num == 58)
        {
            for(int i = 2; i < 5; ++ i)
                if(p[i].num - 1 != p[i - 1].num) return 0;
            return 1;
        }
        return 0;
    }
    else
    {
        for(int i = 3; i >= 0; -- i)
            if(p[i].num + 1 != p[i + 1].num) return 0;
        return 1;
    }
}

bool isF()
{
    for(int i = 1; i < 5; ++ i)
        if(p[i].suit != p[i - 1].suit) return 0;
    return 1;
}

int main()
{
    int n, i, j, score;
    cin>>n;
    for(i = 0; i < n; ++ i)
    {
        score = 0;
        for(j = 0; j < 5; ++ j)
        {
            cin>>p[j].suit>>p[j].num;
            if(p[j].num == 'X') p[j].num = 58;
            else if(p[j].num == 'A') p[j].num = 49;
            else if(p[j].num == 'J') p[j].num = 59;
            else if(p[j].num == 'Q') p[j].num = 60;
            else if(p[j].num == 'K') p[j].num = 61;
        }
        sort(p, p + 5, comp);
        
        if(isF() && isS()) score += 1000;
        else if(isF())
        {
            score += 350;
            if(isFOAK()) score += 750;
            else if(isFH()) score += 500;
            else if(isTOAK()) score += 200;
            else if(isTP()) score += 100;
            else if(isOP()) score += 50;
        }
        else if(isS()) score += 250;
        else
        {
            if(isFOAK()) score += 750;
            else if(isFH()) score += 500;
            else if(isTOAK()) score += 200;
            else if(isTP()) score += 100;
            else if(isOP()) score += 50;
        }
        printf("%d\n", score);
    }
    return 0;
}