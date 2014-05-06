#include<iostream>
#include<vector>
using namespace std;

int poise[20];

int main()
{
    int test, w, t, i, sum;
    poise[0] = 1;
    for(w = 1; w < 20; ++ w) poise[w] = 3 * poise[w - 1];
    vector<int> left, right;
    scanf("%d", &test);
    while(test --)
    {
        scanf("%d", &w);
        left.clear();
        right.clear();
        while(w != 0)
        {
            if(w < 0) t = -w;
            else      t = w;
            sum = 0;
            for(i = 0; ; ++ i)
            {
                sum += poise[i];
                if(sum >= t) break;
            }
            if(w < 0)
            {
                left.push_back(poise[i]);
                w += poise[i];
            }
            else
            {
                right.push_back(poise[i]);
                w -= poise[i];
            }
        }
        if(left.empty()) printf("empty ");
        else
        {
            for(i = left.size() - 1; i >= 1  ; -- i) printf("%d,", left[i]);
            printf("%d ", left[0]);
        }
        if(right.empty()) printf("empty\n");
        else
        {
            for(i = right.size() - 1; i >= 1  ; -- i) printf("%d,", right[i]);
            printf("%d\n", right[0]);
        }
    }
    return 0;
}