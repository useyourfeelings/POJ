#include<iostream>
using namespace std;

char PN[101], words[50000][51], word[51];//, code[51];;
int N, best[101], choice[101];
char ctoi[] = "22233344115566070778889990";
             //abcdefghijklmnopqrstuvwxyz
int LEN, ID, MAX = 10000;

struct TrieNode
{
    int match;   // -1 not match, else word id
    TrieNode *son[10]; // 10 for 0~9
    TrieNode():match(-1)//,count(0)
    {
        for(int i = 0; i < 10; ++ i)
            son[i] = 0;
    }
};

TrieNode *head;

void addWord()//int pos)
{
    TrieNode *current = head;
    TrieNode *next;
    int len = strlen(word);
    int index, pos;
    for(pos = 0; pos < len; ++ pos)
    {
        index = word[pos] - '0';
        next = current->son[index];
        if(next == 0) // new
        {
            next = new TrieNode;
            current->son[index] = next;
        }
        current = next;
    }
    current->match = ID;
}

int work(int startpos)
{
    if(startpos > LEN) return -1;// fail
    if(startpos == LEN) return 0;// done
    if(best[startpos] != -2) return best[startpos];
    TrieNode *current = head, *next;
    int index, currentpos = startpos, minwords = MAX, who, ret;
    for(; currentpos < LEN;) // try every word we found
    {
        index = PN[currentpos] - '0';
        next = current->son[index];
        if(next == 0) // over
            break;
        if(next->match != -1) // found one
        {
            ret = work(currentpos + 1);
            if(ret != -1) // ok
            {
                ++ ret;
                if(ret < minwords) // compare
                {
                    minwords = ret;
                    who = next->match;
                }
            }
        }
        current = next;
        ++ currentpos;
    }
    if(minwords == MAX) minwords = -1;
    best[startpos] = minwords;
    choice[startpos] = who;
    return minwords;
}

void input()
{
    scanf("%s\n%d\n", PN, &N);
    LEN = strlen(PN);
    for(int i = 0; i < LEN; ++ i) best[i] = -2;
    for(ID = 0; ID < N; ++ ID)
    {
        scanf("%s\n", words[ID]);
        int i = strlen(words[ID]), j;
        for(j = 0; j < i; ++ j) word[j] = ctoi[words[ID][j] - 'a'];
        word[j] = '\0';
        addWord();
    }
}

void output()
{
    int pnlen = strlen(PN), len, pos;
    for(pos = 0; pos < pnlen;)
    {
        len = strlen(words[choice[pos]]);
        printf("%s ", words[choice[pos]]);
        pos += len;
    }
}

int main()
{
    head = new TrieNode;
    input();
    work(0);
    output();
}