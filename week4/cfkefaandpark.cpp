#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;


int total =0;
void dfs(ll s,ll sum,vector<vector<int>>&adj,vector<int>&vis,int m,int cc[])
{
    if(vis[s])
        return;
 
    vis[s]=1;
 
    if(cc[s])
        sum++;
    else
        sum=0;
 
    if(sum>m)
        return;
 
    if(s!=0 && adj[s].size()==1)
    {
        total++;
    }
    for(int i=0;i<adj[s].size();i++)
    {
        dfs(adj[s][i],sum,adj,vis,m,cc);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>vis(n,0);
    int check[n];
    for(int i=0;i<n;i++)
    {
        cin>>check[i];
    }
    vector<vector<int>> ng(n);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        ng[a-1].push_back(b-1);
        ng[b-1].push_back(a-1);
    }
    dfs(0,0,ng,vis,m,check);
    cout<<total;
    return 0;
}