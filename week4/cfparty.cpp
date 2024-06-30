#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;

void label(int x,int arr[],int lev[],int vis[],int n,int cur=0)
{
    vis[x] =1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==-1)
        {
            if(arr[i]==x)
            {
                lev[i]=cur+1;
                label(i,arr,lev,vis,n,cur+1);
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    int *lev = new int[n];
    int *vis = new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i] =-1;
        lev[i] =-1;
        vis[i] =-1;
    }
    int done =0;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr[i] = a-1;
        if(a==-1)
        {
            lev[i]=0;
            done++;
        }
    }
    int x = 0;
    for(int i=0;i<n;i++)
    {
        if(lev[i]==0)
        label(i,arr,lev,vis,n);
    }
    int m=0;
    for(int i=0;i<n;i++)
    {
        m = max(m,lev[i]);
    }
    cout<<m+1<<endl;
    return 0;
}