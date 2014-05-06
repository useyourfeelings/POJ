#include<iostream>
using namespace std;
int fun(int in, int val, int N, int M, int pa[], int** pb)
{
    if(in == N - 1) return pb[in][val] = 1;
    if(pb[in][val] != -1) return pb[in][val];
    if(val * 2 > M) return pb[in][val] = 0;
    int sum = 0;
    for(int k = val * 2; k <= pa[in + 1]; k++)
        sum += fun(in + 1, k, N, M, pa, pb);
    return pb[in][val] = sum;
}
int main()
{
    int s, N, M, sum;
    cin>>s;
    for(int Case = 1; Case <= s; Case++)
    {
        sum = 0;
        cin>>N>>M;
        int *pa = new int[N];
        int **pb = new int *[N];
        for(int i = 0; i < N; i++)
            pb[i] = new int[M + 1];
        for(int i = 0; i < N; i++)
            for(int j = 0; j < M + 1; j++)
                pb[i][j] = -1;
        pa[N - 1] = M;
        for(int i = N - 2; i >= 0; i--) pa[i] = pa[i + 1] / 2;
        for(int val = 1; val <= pa[0]; val++)
            sum += fun(0, val, N, M, pa, pb);
        cout<<"Case "<<Case<<": n = "<<N<<", m = "<<M
            <<", # lists = "<<sum<<endl;
        delete []pa;
        for(int i = 0; i < N; i++)
            delete pb[i];
        delete []pb;
    }
    return 0;
}