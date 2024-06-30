class Solution {
public:
    int longestCycle(vector<int>& edges) 
    {
       
        vector<int>visited(edges.size(),0);
        vector<bool>globalVisited(edges.size(),0);
        int ans=-1;
        for(int i=0;i<edges.size();i++)
        {
            if (visited[i]==0)
            {
                int temp=dfs(visited,edges,i,0,globalVisited);
                if (temp!=0)
                {
                    ans=max(ans,temp);
                }
            }
        }
        return ans;    
    }
    int dfs(vector<int>&visited,vector<int>&edges,int i,int count,vector<bool>&globalVisited)
    {
        if (globalVisited[i])
        {
            return -1;
        }
        if (edges[i]==-1)
        {
            globalVisited[i]=1;
            return -1;
        }
        if (visited[i]!=0)
        {
            return count-visited[i]+1;
        }
        visited[i]=count+1;
        int ans= dfs(visited,edges,edges[i],count+1,globalVisited);
        visited[i]=0;
        globalVisited[i]=1;
        return ans;

    }
};