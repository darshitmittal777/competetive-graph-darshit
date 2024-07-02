class Solution {
public:
    int t=0;
    bool cyc = false;
    vector<int> ans;
    void DFS(vector<vector<int>> &adj,vector<int> &time,vector<int> &vis,int x)
    {
        vis[x] = 1;
        for(auto it = adj[x].begin();it!=adj[x].end();it++)
        {
            if(vis[*it]==0)
            {
                DFS(adj,time,vis,*it);
            }
            else if(vis[*it]==1)
            {
                cyc = true;
                return;
            }
        }
        vis[x] = 2;
        time[x] = t;
        t++;
        ans.push_back(x);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> check(numCourses,0);
        vector<int> time(numCourses,-1);

        for(auto it = prerequisites.begin();it!=prerequisites.end();it++)
        {
            adj[(*it)[0]].push_back((*it)[1]);
        }

        for(int i=0;i<adj.size();i++)
        {
            if(!check[i])
            DFS(adj,time,check,i);
            if(cyc)
            return{};
        }
        return ans;
    }
};