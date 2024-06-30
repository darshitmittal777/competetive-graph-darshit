class Solution {
public:
    int nextId=0;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto el : connections)
        {
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
        }
        vector<int> vis(n,0),lowest(n);
        vector<vector<int>> ans;
        dfs(adj,vis,lowest,-1,0,ans);
        return ans;
    }
    void dfs(vector<int> adj[],vector<int> &vis,vector<int> &lowest,int parentId,int node,
                vector<vector<int>> &ans)
    {
        vis[node] = 1;
        lowest[node] = nextId;
        nextId++;
        int cur_lowest = lowest[node];
        for(auto x: adj[node])
        {
            if(x == parentId) continue;
            if(!vis[x])
            dfs(adj,vis,lowest,node,x,ans);
            lowest[node] =min(lowest[node],lowest[x]);
            if(cur_lowest < lowest[x])
            ans.push_back({node,x}); 
        }
    }
};