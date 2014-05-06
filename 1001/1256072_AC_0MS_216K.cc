#include<iostream>
using namespace std;
struct Big
{
    Big(void):head(0),fb(0)
    {
        for(int i = 0; i < 150; i++) arr[i] = 0;
    }
    Big(char *p, int f):fb(f)
    {
        int i;
        for(i = 5; i < 150; i++) arr[i] = 0;
        for(i = 0; i <= 4; i++)
        {
            arr[4 - i] = int(p[i]) - 48;
            if(p[i] != 0) head = i;
        }
    }
    int arr[150];
    int head;
    int fb;
    void print(void);
    void operator =(Big &t)
    {
        for(int i = 0; i < 150; i++) arr[i] = t.arr[i];
        head = t.head;
        fb = t.fb;
    }
    void mul(const Big &);
    void badplus(const Big &);
};

void Big::print(void)
{
    int i, tail = fb;
    for(i = 0; i < fb; i++)
    {
        if(arr[i] != 0)
        {
            tail = i;
            break;
        }
    }
    for(i = 149; i >= fb; i--) if(arr[i] != 0) break;
    for(; i >= fb; i--) cout<<arr[i];
    if(tail == fb)
    {
        cout<<endl;
        return;
    }
    cout<<".";
    for(; i >= tail; i --) cout<<arr[i];
    cout<<endl;
}
void Big::badplus(const Big &b)
{
    int i;
    int end = max(head, b.head);
    for(i = 0; i <= end; i++)
    {
        arr[i + 1] += (arr[i] + b.arr[i]) / 10;
        arr[i] = (arr[i] + b.arr[i]) % 10;
    }
    if(arr[i] != 0) head = i + 1;
    else head = i;
}

void Big::mul(const Big &b)
{
    int i, j, k, c, y;
    Big answer;
    for(j = 0; j <= b.head; j++)
    {
        Big t;
        c = 0;
        for(i = 0; i <= head; i++)
        {
            y = arr[i] * b.arr[j];
            t.arr[i + j] = (y + c) % 10;
            c = (y + c) / 10;
        }
        t.arr[i + j] = c;
        if(arr[i + j] == 0) t.head = i + j;
        else t.head = i + j - 1;
        answer.badplus(t);
    }
    head = answer.head;
    for(i = 0; i <= head; i++) arr[i] = answer.arr[i];
    fb += b.fb;
}

int main()
{
    char r[6];
    int n, i, f;
    while(cin>>r>>n)
    {
        for(i = 0; i <= 4; i++)
        {
            if(r[i] == '.')
            {
                f = 5 - i;
                break;
            }
        }
        for(;i < 5; i++) r[i] = r[i + 1];
        r[5] = 0;
        Big big(r, f);
        while(--n)
        {
            Big t(r, f);
            big.mul(t);
        }
        big.print();
    }
    return 0;
}