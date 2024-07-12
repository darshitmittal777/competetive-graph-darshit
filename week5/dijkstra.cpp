#define ll  long long int
#include <bits/stdc++.h>
using namespace std;


vector<int> dijkstra(int n,vector<vector<pair<int,ll>>> &adjList){
    set <pair<ll,int>> st;
    st.insert({0,1});

    vector<ll> dist(n+1,1e18);
    dist[1]=0;
    vector<int> par(n+1,-1);

    while(!st.empty()){
        pair<ll,int> node = *st.begin();
        st.erase(node);
        int currNode = node.second;
        ll weight = node.first;
        for(auto neighbour:adjList[currNode]){
            if(weight+neighbour.second<dist[neighbour.first]){
                par[neighbour.first]=currNode;
                st.erase({dist[neighbour.first],neighbour.first});
                dist[neighbour.first]=weight+neighbour.second;
                st.insert({dist[neighbour.first],neighbour.first});
            }
        }
    }
    return par;
}   

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,ll>>> adjList(n+1);

    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    } 

    vector<int> ans;
    ans = dijkstra(n,adjList);
    
    if(ans[n]==-1){cout<<-1;return 0;} 

    int node=n;
    vector<int> finalAns;
    while(node!=-1){
        finalAns.push_back(node);
        node=ans[node];
    }
    reverse(finalAns.begin(),finalAns.end());   
    for(int i=0;i<finalAns.size();i++){
        cout<<finalAns[i]<<" ";
    }
    return 0;
}