class Solution {
    
    private:
    
    int timer = 0;
    
    void DFS(int node, int parent, vector<bool> &vis, vector<int> &mark, int tin[], int low[], vector<int> adj[]){
        
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        
        for(auto it : adj[node]){
            if(it == parent) continue;
            
            if(!vis[it]){
                
                DFS(it, node, vis, mark, tin, low, adj);
                low[node] = min(low[it], low[node]);
                if(low[it] >= tin[node] && parent != -1)
                  mark[node] = 1;
                  
                child++;
                
            }else{
                low[node] = min(low[node], tin[it]);
            }
            
        }
        
        if(child > 1 && parent == -1)
          mark[node] = 1;
        
    }
    
    public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        
        vector<bool> vis(n, 0);
        vector<int> mark(n, 0);
        int tin[n], low[n];
        
        for(int i=0; i<n; i++){
            if(!vis[i])
               DFS(i, -1, vis, mark, tin, low, adj);
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(mark[i] == 1){
                ans.push_back(i);
            }
        }
        
        if(ans.size() == 0)
           return {-1};
        
        return ans;
        
    }
};