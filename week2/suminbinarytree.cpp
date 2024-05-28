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
        ll sum=0;
        ll a;
        cin>>a;
        while(a>0)
        {
            sum += a;
            a = a/2;
        }
        cout<<sum<<endl;
        t--;
    }
    return 0;
}