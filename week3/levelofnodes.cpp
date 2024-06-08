#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;

int nodeLevel(int V, vector<int> adj[], int X) 
{
    // code here
    vector<int> check(V,-1);
    queue<int>q;
    q.push(0);
    check[0] = 0;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(vector<int>::iterator i = adj[current].begin();i!=adj[current].end();i++)
        {
            if(check[(*i)] == -1)
            {
                q.push(*i);
                check[*i] =  check[current]+1;
            }
            if(*i==X)
            return(check[current]+1);
        }
    }
    return(-1);
}