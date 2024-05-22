#include<iostream>
#include<cmath>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        ll n,k;
        cin>>n>>k;
        ll m = k;
        if(n>k)
        {
            ll x = n/k;
            k = k * x;
            while(n>k)
            k = k + m;
        }
        ll min = k/n;
        ll max = k;
        ll mid = min +(max-min)/2;
        ll possible =max;
        while(min<=max)
        {
            if(mid*n>k)
            {
                possible = mid;
                max = mid-1;
            }
            else if(mid*n<k)
            {
                min = mid+1;
            }
            else
            {
                possible = mid;
                break;
            }
            mid = min +(max-min)/2;
        }
        cout<<possible<<endl;
        t--;
    }
    return 0;
}