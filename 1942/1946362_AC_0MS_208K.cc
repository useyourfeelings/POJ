#include<iostream>
using namespace std;

long long CC(unsigned int m,unsigned int n)
{
	if(n==0) return 1;
	if(n==1) return m;
	if(n>(m>>1)) return CC(m,m-n);
	return CC(m-1,n-1)*m/n;
}

int main()
{
    long long a, b;
    while(cin>>a>>b && a + b > 0)
        cout<<CC(a + b, a)<<endl;
    system("pause");
    return 0;
}