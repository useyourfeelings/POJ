include<iostream>
int main()
{
    int t, len, n, a, b, k;
    scanf("%d", &t);
    while(t --)
    {
        a = -1;
        b = -1;
        scanf("%d%d", &len, &n);
        while(n --)
        {
            scanf("%d", &k);
            if(k > len / 2)
            {
                if(len - k > a) a = len - k;
                if(k > b) b = k;
            }
            else
            {
                if(k > a) a = k;
                if(len - k > b) b = len - k;
            }
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}