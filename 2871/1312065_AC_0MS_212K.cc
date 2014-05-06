#include<iostream>
using namespace std;

int main()
{
    double a, b;
    scanf("%lf", &a);
    while(scanf("%lf", &b) && b != 999)
    {
        printf("%.2lf\n", b - a);
        a = b;
    }
    printf("End of Output\n");
    system("pause");
    return 0;
}