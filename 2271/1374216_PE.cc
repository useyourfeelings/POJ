#include<iostream>
using namespace std;

char buff[81];

int main()
{
    int count = 0;
    while(scanf("%s", &buff) != EOF)
    {
        if(buff[0] == '<')
        {
            if(buff[1] == 'b')
            {
                count = 0;
                printf("\n\n");
            }
            else
            {
                if(count != 0)
                {
                    printf("\n");
                    count = 0;
                }
                printf("----------------------------------------"
                       "----------------------------------------\n");
            }
        }
        else
        {
            if(buff[strlen(buff) - 1] == '\n')
                buff[strlen(buff) - 1] = 0;
            if(count + strlen(buff) > 80)
            {
                printf("\n%s ", buff);
                count = strlen(buff) + 1;
            }
            else
            {
                printf("%s ", buff);
                count += (strlen(buff) + 1);
            }
        }
    }
    return 0;
}
