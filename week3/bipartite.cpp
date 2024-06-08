class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> check(graph.size(),-1);
        for(int i=0;i<graph.size();i++)
        {
            if(check[i]==1)
            continue;
            queue<int>q;
            q.push(i);
            vector<int> color(graph.size(),-1);
            color[i] = 0;
            check [i]=1;
            while(!q.empty())
            {
                int current = q.front();
                q.pop();
                for(auto it = graph[current].begin();it!=graph[current].end();it++)
                {
                    check[*it] = 1;
                    if(color[*it]==-1)
                    {
                        q.push(*it);
                        color[*it] = (color[current] + 1)%2;
                    }
                    else if(color[*it]==color[current])
                    return false;
                }
            }
        }
        return true;
    }
};