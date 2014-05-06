#include<iostream>
#include<list>
using namespace std;

list<char> card[4][4];//n e s w  // c d s h
char line[] = "+---+---+---+---+---+---+---+---+---+---+---+---+---+";

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
    int i, player;
    char p, suit, rank;
    while(scanf("%c", &p) && p != '#')
    {
        switch(p)
        {
            case 'N': player = 1; break;
            case 'E': player = 2; break;
            case 'S': player = 3; break;
            case 'W': player = 0; break;
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
        /////////////////////////////////
        printf("South player:\n");
        printf("%s\n|", line);
        for(i = 0; i < 4; ++ i)
        {
            card[2][i].sort(comp);
            list<char>::iterator itr = card[2][i].begin();
            for(; itr != card[2][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n|");
        for(player = 0; player < card[2][0].size(); ++ player)
            printf(" C |");
        for(player = 0; player < card[2][1].size(); ++ player)
            printf(" D |");
        for(player = 0; player < card[2][2].size(); ++ player)
            printf(" S |");
        for(player = 0; player < card[2][3].size(); ++ player)
            printf(" H |");
        printf("\n|");
        for(i = 0; i < 4; ++ i)
        {
            list<char>::iterator itr = card[2][i].begin();
            for(; itr != card[2][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n%s\n", line);
        /////////////////////////
        printf("West player:\n");
        printf("%s\n|", line);
        for(i = 0; i < 4; ++ i)
        {
            card[3][i].sort(comp);
            list<char>::iterator itr = card[3][i].begin();
            for(; itr != card[3][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n|");
        for(player = 0; player < card[3][0].size(); ++ player)
            printf(" C |");
        for(player = 0; player < card[3][1].size(); ++ player)
            printf(" D |");
        for(player = 0; player < card[3][2].size(); ++ player)
            printf(" S |");
        for(player = 0; player < card[3][3].size(); ++ player)
            printf(" H |");
        printf("\n|");
        for(i = 0; i < 4; ++ i)
        {
            list<char>::iterator itr = card[3][i].begin();
            for(; itr != card[3][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n%s\n", line);
        ///////////////////////////
        printf("North player:\n");
        printf("%s\n|", line);
        for(i = 0; i < 4; ++ i)
        {
            card[0][i].sort(comp);
            list<char>::iterator itr = card[0][i].begin();
            for(; itr != card[0][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n|");
        for(player = 0; player < card[0][0].size(); ++ player)
            printf(" C |");
        for(player = 0; player < card[0][1].size(); ++ player)
            printf(" D |");
        for(player = 0; player < card[0][2].size(); ++ player)
            printf(" S |");
        for(player = 0; player < card[0][3].size(); ++ player)
            printf(" H |");
        printf("\n|");
        for(i = 0; i < 4; ++ i)
        {
            list<char>::iterator itr = card[0][i].begin();
            for(; itr != card[0][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n%s\n", line);
        ///////////////////////////////
        printf("East player:\n");
        printf("%s\n|", line);
        for(i = 0; i < 4; ++ i)
        {
            card[1][i].sort(comp);
            list<char>::iterator itr = card[1][i].begin();
            for(; itr != card[1][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n|");
        for(player = 0; player < card[1][0].size(); ++ player)
            printf(" C |");
        for(player = 0; player < card[1][1].size(); ++ player)
            printf(" D |");
        for(player = 0; player < card[1][2].size(); ++ player)
            printf(" S |");
        for(player = 0; player < card[1][3].size(); ++ player)
            printf(" H |");
        printf("\n|");
        for(i = 0; i < 4; ++ i)
        {
            list<char>::iterator itr = card[1][i].begin();
            for(; itr != card[1][i].end(); ++ itr)
                cout<<*itr<<" "<<*itr<<"|";
        }
        printf("\n%s\n", line);
    }
    return 0;
}