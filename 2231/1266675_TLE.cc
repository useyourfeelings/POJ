#include<iostream>
#include<vector>
using namespace std;

char bmax[] = "9999999999999999";

struct Big
{
    Big(const Big &t)
    {
        head = t.head;
        for(int i = 0; i < 17; i++) arr[i] = t.arr[i];
    }
    Big(char *p)
    {
        int i, j;
        for(i = strlen(p) - 1, j = 0; i >= 0; i--, j++)
            arr[i] = p[j] - 48;
        for(i = strlen(p); i < 17; i++) arr[i] = 0;
        head = strlen(p) - 1;
        arr[16] = 0;
    }
    char cmp(const Big &);
    void print(void);
    void plus(const Big &);
    void minus(const Big &);
    void operator =(Big &t)
    {
        for(int i = 0; i < 17; i++) arr[i] = t.arr[i];
        head = t.head;
    }
    char arr[17];
    short head;
};

char Big::cmp(const Big &t)
{
    if(head < t.head) return 'L';
    if(head > t.head) return 'G';
    for(int i = head; i >= 0; i--)
    {
        if(arr[i] > t.arr[i]) return 'G';
        if(arr[i] < t.arr[i]) return 'L';
    }
    return 'E';
}

void Big::print(void)
{
    int i;
    for(i = head; i >= 0; i--) cout<<char(arr[i] + 48);
    cout<<endl;
}

void Big::plus(const Big &t)
{
    int i, end;
    end = max(head, t.head);
    for(i = 0; i <= end; i++)
    {
        arr[i + 1] += (arr[i] + t.arr[i]) / 10;
        arr[i] = (arr[i] + t.arr[i]) % 10;
    }
    if(arr[i] != 0) head = i;
    else head = end;
}
void Big::minus(const Big &t)
{
    Big y(bmax);
    int i;
    for(i = 0; i < 16; i++)
    {
        if((arr[i] = y.arr[i] - arr[i]) != 0);
            head = i;
    }
    this -> plus(t);
    for(i = 0; i < 16; i++)
    {
        if((arr[i] = y.arr[i] - arr[i]) != 0)
            head = i;
    }
}


int main()
{   
    char p[10];
    int n, i, j;
    cin>>n;
    vector<Big> vb;
    vb.reserve(n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", &p);
        vb.push_back(Big(p));
    }
    Big sum("0");
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(vb[i].cmp(vb[j]) == 'E') continue;
            if(vb[i].cmp(vb[j]) == 'G')
            {
                Big t(vb[i]);
                t.minus(vb[j]);
                sum.plus(t);
                sum.plus(t);
            }
            else
            {
                Big t(vb[j]);
                t.minus(vb[i]);
                sum.plus(t);
                sum.plus(t);
            }
        }
    }
    sum.print();
    return 0;
}