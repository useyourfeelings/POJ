#include<iostream>
using namespace std;

int main()
{
    char t[101];
    int n, i, j, head, len, pre;
    bool ing, s, again;
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; ++ i)
    {
        again = ing = s = head = pre = 0;
        gets(t);
        len = strlen(t);
        if(len > 2 && t[0] == 'u' && t[1] == 'n')
        {
            printf("not ");
            head = 2;
            pre = 2;
        }
        else if(len > 2 && t[0] == 'r' && t[1] == 'e')
        {
            head = 2;
            again = 1;
            pre = 2;
        }
        else if(len > 4 && t[0] == 'p' && t[1] == 'o' &&
                            t[2] == 's' && t[3] == 't')
        {
            printf("after ");
            head = 4;
            pre = 4;
        }
        else if(len > 3 && t[0] == 'p' && t[1] == 'r' &&
                            t[2] == 'e')
        {
            printf("before ");
            head = 3;
            pre = 3;
        }
        else if(len > 4 && t[0] == 'a' && t[1] == 'n' &&
                            t[2] == 't' && t[3] == 'i')
        {
            printf("against ");
            head = 4;
            pre = 4;
        }
        if(len > 2 + pre && t[len - 1] == 'r' && t[len - 2] == 'e')
        {
            printf("one who ");
            len -= 2;
            s = 1;
        }
        else if(len > 3 + pre && t[len - 1] == 'g' && t[len - 2] == 'n' &&
                            t[len - 3] == 'i')
        {
            printf("to actively ");
            len -= 3;
        }
        else if(len > 3 + pre && t[len - 1] == 'e' && t[len - 2] == 'z' &&
                            t[len - 3] == 'i')
        {
            printf("change into ");
            len -= 3;
        }
        else if(len > 4 + pre && t[len - 1] == 'n' && t[len - 2] == 'o' &&
                            t[len - 3] == 'i' && t[len - 4] == 't')
        {
            printf("the process of ");
            len -= 4;
            ing = 1;
        }
        else if(len > 1 + pre && t[len - 1] == 's')
        {
            printf("multiple instances of ");
            len -= 1;
        }
        for(j = head; j < len; ++ j) printf("%c", t[j]);
        if(s) printf("s");
        if(again) printf(" again");
        if(ing) printf("ing");
        printf("\n");
    }
    return 0;
}
