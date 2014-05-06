#include<iostream>
using namespace std;

char text[40000][81];
int PosOfRef[1000];
int OldRefOfRef[1000];
int NewRefOfRef[1000];

int main()
{
    memset(NewRefOfRef, sizeof(NewRefOfRef), 0);
    int line = 0, i, j, ref, count = 1;
    while(gets(text[line])) ++ line;
    for(i = 0; i < line;)
    {
        // i'm not empty line
        if(text[i][0] == '[')              //    description
        {
            ref = atoi(text[i] + 1);
            PosOfRef[ref] = i;
            for(++ i; i < line; ++ i)
            {
                if(strlen(text[i]) == 1)
                {
                    ++ i;
                    break;
                }
            }
            while(strlen(text[i]) == 1) ++ i;
        }
        else             //    text
        {
            for(;;)
            {
                for(j = 0; ;)
                {
                    printf("%c", text[i][j]);
                    if(text[i][j] == '[')
                    {
                        ref = atoi(text[i] + j + 1);
                        if(NewRefOfRef[ref] == 0)
                        {
                            NewRefOfRef[ref] = count;
                            OldRefOfRef[count] = ref;
                            printf("%d", count);
                            ++ count;
                        }
                        else
                        {
                            printf("%d", NewRefOfRef[ref]);
                        }
                        ++ j;
                        while(text[i][j ++] != ']');
                        printf("]");
                    }
                    else ++ j;
                    if(text[i][j] == '\n')
                    {
                        printf("\n");
                        break;
                    }
                }
                ++ i;
                if(i >= line) break;
                if(strlen(text[i]) == 1)  //   empty line
                {
                    for(++ i; i < line; ++ i)
                        if(strlen(text[i]) != 1) break;
                    printf("\n");
                    break;
                }
            }
        }
    }
    for(i = 1; i < count; ++ i)
    {
        printf("\n");
        j = PosOfRef[OldRefOfRef[i]];
        ref = 2;
        while(text[j][ref] != ']') ++ ref;
        printf("[%d]%s", i, text[j] + ref + 1);
        ++ j;
        while(strlen(text[j]) != 1) printf("%s", text[j ++]);
    }
    return 0;
}