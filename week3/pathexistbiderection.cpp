class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if(source==destination)
    return true;
    vector<int>adj[n];
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int>reached(n,0);
    queue<int>q;
    q.push(source);
    reached[source] = 1;
    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(vector <int>::iterator it = adj[current].begin();it!=adj[current].end();it++)
        {
            if(reached[(*it)]==0)
            {
                q.push(*it);
                reached[(*it)]=1;
            }
            if(*it==destination)
            return true;
        }
    }
    return false;    
    }
};