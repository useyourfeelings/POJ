#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> card[4][4];//s w n e  // c d s h
char line[] = "+---+---+---+---+---+---+---+---+---+---+---+---+---+";
char name[4][15] = {"Souh player:\n", "West player:\n",
                   "North player:\n", "East player:\n"};

bool comp(char a, char b)
{
    if(a < 58)
    {
        if(b < 58) return a < b;
        else return 1;
    }
    else
    {
        if(b < 58) return 0;
        else
        {
            if(a == 'J')
            {
                if(b == 'T') return 0;
                else return 1;
            }
            if(b == 'J')
            {
                if(a == 'T') return 1;
                else return 0;
            }
            return a >= b;
        }
    }
}

int main()
{
    int i, player, k;
    char p, suit, rank;
    while(scanf("%c", &p) && p != '#')
    {
        switch(p)
        {
            case 'N': player = 3; break;
            case 'E': player = 0; break;
            case 'S': player = 1; break;
            case 'W': player = 2; break;
        }
        getchar();
        for(i = 0; i < 26; ++ i, player = (player + 1) % 4)
        {
            scanf("%c%c", &suit, &rank);
            switch(suit)
            {
                case 'C': card[player][0].push_back(rank); break;
                case 'D': card[player][1].push_back(rank); break;
                case 'S': card[player][2].push_back(rank); break;
                case 'H': card[player][3].push_back(rank); break;
            }
        }
        getchar();
        for(i = 0; i < 26; ++ i, player = (player + 1) % 4)
        {
            scanf("%c%c", &suit, &rank);
            switch(suit)
            {
                case 'C': card[player][0].push_back(rank); break;
                case 'D': card[player][1].push_back(rank); break;
                case 'S': card[player][2].push_back(rank); break;
                case 'H': card[player][3].push_back(rank); break;
            }
        }
        getchar();
        for(k = 0; k < 4; ++ k)
        {
            printf("%s", name[k]);
            printf("%s\n|", line);
            for(i = 0; i < 4; ++ i)
            {
                sort(card[k][i].begin(), card[k][i].end(), comp);
                for(player = 0; player < card[k][i].size(); ++ player)
                    printf("%c %c|", card[k][i][player], card[k][i][player]);
            }
            printf("\n|");
            for(player = 0; player < card[k][0].size(); ++ player)
                printf(" C |");
            for(player = 0; player < card[k][1].size(); ++ player)
                printf(" D |");
            for(player = 0; player < card[k][2].size(); ++ player)
                printf(" S |");
            for(player = 0; player < card[k][3].size(); ++ player)
                printf(" H |");
            printf("\n|");
            for(i = 0; i < 4; ++ i)
            {
                for(player = 0; player < card[k][i].size(); ++ player)
                    printf("%c %c|", card[k][i][player], card[k][i][player]);
            }
            printf("\n%s\n", line);
        }
    }
    return 0;
}