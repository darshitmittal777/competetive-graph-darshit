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
        int n;cin>>n;
        int *arr = new int[n];
        int a,b;
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
        }
        for(int i=0;i<n-1;i++)
        {
            cin>>a>>b;
            arr[a-1]++;
            arr[b-1]++;
        }
        int ans=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==1)
            cnt++;
        }
        ans = (cnt+1)/2;
        cout<<ans<<endl;
        t--;
    }
    return 0;
}