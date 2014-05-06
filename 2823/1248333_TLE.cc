#include<iostream>
#include<vector>
#include<cmath>
#include<limits>
using namespace std;

int main()
{   
    int n, k, t, i, j, size, range, minv , maxv, end, start;
    cin>>n>>k;
    range = sqrt(n);
    size = ceil(n / range);
    vector<int> arr;
    vector<int> maxa;
    vector<int> mina;
    vector<int> maxr;
    arr.reserve(n);
    mina.reserve(size);
    maxa.reserve(size);
    maxr.reserve(n - k + 1);
    
    cin>>arr[0];
    minv = arr[0];
    maxv = minv;
    
    for(i = 1; ; i++)
    {
        scanf("%d", &arr[i]);
        if(i % range == 0)
        {
            mina[i / range - 1] = minv;
            maxa[i / range - 1] = maxv;
            minv = arr[i];
            maxv = minv;
        }
        else
        {
            if(arr[i] > maxv) maxv = arr[i];
            else if(arr[i] < minv) minv = arr[i];
        }
        if(i == n - 1) break;
    }
    for(i = 0; i <= n - k; i++)
    {
        minv = INT_MAX;
        maxv = INT_MIN;
        if(i % range + k <= range)
        {
            for(j = i; j < i + k; j++)
            {
                if(arr[j] > maxv) maxv = arr[j];
                if(arr[j] < minv) minv = arr[j];
            }
            cout<<minv<<" ";
            maxr.push_back(maxv);
            continue;
        }
        if(i % range == 0) end = i;
        else end = range - i % range + i;
        if((i + k) % range == 0)
            start = end + ((k - end + i) / range) * range - range;
        else start =  end + ((k - end + i) / range) * range;
        for(j = i; j < end; j++)
        {
            if(arr[j] > maxv) maxv = arr[j];
            if(arr[j] < minv) minv = arr[j];
        }
        if(end != start)
        {
            int inend = start / range - 1;
            for(j = end / range; j <= inend; j++)
            {
                if(maxa[j] > maxv) maxv = maxa[j];
                if(mina[j] < minv) minv = mina[j];
            }
        }
        int outend = i + k;
        for(j = start; j < outend; j++)
        {
            if(arr[j] > maxv) maxv = arr[j];
            if(arr[j] < minv) minv = arr[j];
        }
        cout<<minv<<" ";
        maxr.push_back(maxv);
    }
    
    vector<int>::iterator itr;
    cout<<endl;
    for(itr = maxr.begin(); itr != maxr.end(); ++itr) cout<<*itr<<" ";
    cout<<endl;
    return 0;
}