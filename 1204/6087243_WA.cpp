#include<iostream>
using namespace std;

char g[1001][1001];
char word[1001];

int num, remain, R, C, len, dir, id, sr, sc;
char dirTag[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
                      //  H A B
                      //  G # C
                      //  F E D
int move[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int resultpos[1000][2];
char resultdir[1000];

struct TrieNode
{
    int match;   // -1 not match, else word id
    int count;
    TrieNode *son[26];
    TrieNode():match(-1),count(0)
    {
        for(int i = 0; i < 26; ++ i)
            son[i] = 0;
    }
};

char pivot = 'A';
TrieNode *head;
TrieNode *current;
TrieNode *next;

void delTree(TrieNode *node)
{
    for(int i = 0; i < 26; ++ i)
    {
        if(node->son[i] != 0)
            delTree(node->son[i]);
    }
    delete node;
    node = 0;
}

void addWord(int pos)
{
    ++ current->count;
    int index = word[pos] - pivot;
    next = current->son[index];
    if(next == 0) // new
    {
        next = new TrieNode;
        current->son[index] = next;
    }
    if(pos == len - 1) // over
    {
        next->match = id;
        ++ next->count;
        return;
    }
    current = next;   // else continue
    addWord(pos + 1);
}

int searchWord(int r, int c, int found)
{
    if(r < 0 || r >= R || c < 0 || c >= C) // out
        return found;
    int index = g[r][c] - pivot;
    next = current->son[index];
    if(next == 0)      // fail
        return found;
    if(next->match != -1) // find one
    {
        resultdir[next->match] = dir;
        resultpos[next->match][0] = sr;
        resultpos[next->match][1] = sc;
        -- next->count;    // "delete" it
        next->match = 0;   // "delete" it
        ++ found;
        if(next->count == 0)
            return found;
    }
    current = next;   // else continue
    return searchWord(r + move[dir][0], c + move[dir][1], found);
}

void input()
{
    head = new TrieNode;
    scanf("%d %d %d\n", &R, &C, &num);
    remain = num;
    for(int i = 0; i < R; ++ i)
        scanf("%s\n", g[i]);
    for(id = 0; id < num; ++ id)
    {
        scanf("%s\n", word);
        current = head;
        len = strlen(word);
        addWord(0);
    }
}

void output()
{
    for(int i = 0; i < num; ++ i)
        printf("%d %d %c\n",
            resultpos[i][0], resultpos[i][1], resultdir[i] + pivot);
}

void search()
{
    for(sr = 0; sr < R; ++ sr)
    {
        for(sc = 0; sc < C; ++ sc)
        {
            for(dir = 0; dir < 8; ++ dir)
            {
                current = head;
                remain -= searchWord(sr, sc, 0);
                if(remain == 0) return;
            }
        }
    }
}

int main()
{
    input();
    search();
    output();
    delTree(head);
    return 0;
}
