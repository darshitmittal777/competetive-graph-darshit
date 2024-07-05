int Solution::solve(int A, vector<vector<int> > &B, int C, int D, vector<vector<int> > &E) {
    vector<vector<pair<int,pair<int,int>>>> adj(A+1);
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]].push_back({B[i][1],{B[i][2],0}});
        adj[B[i][1]].push_back({B[i][0],{B[i][2],0}});
    }
    for(int i=0;i<E.size();i++)
    {
        adj[E[i][0]].push_back({E[i][1],{E[i][2],1}});
        adj[E[i][1]].push_back({E[i][0],{E[i][2],1}});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>>dis(A+1,vector<int>(2,1e9));
    dis[C][0]=0;dis[C][1]=0;
    pq.push({0,{C,0}});
    pq.push({0,{C,1}});
    while(!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int weight = cur.first;
        int type = cur.second.second;
        int node = cur.second.first;
        if (weight > dis[node][type]) continue; // Added continue here
        for(auto it = adj[node].begin();it!=adj[node].end();it++)
        {
            int weight_n = (*it).second.first;
            int type_n = (*it).second.second;
            int node_n = (*it).first;
            if(type == 1)
            {
                if(type_n==0)
                {
                    if(weight+weight_n<dis[node_n][1])
                    {
                        dis[node_n][1]=weight+weight_n;
                        pq.push({dis[node_n][1],{node_n,1}});
                    }
                }
            }
            else
            {
                if(type_n==0)
                {
                    if(weight+weight_n<dis[node_n][0])
                    {
                        dis[node_n][0]=weight+weight_n;
                        pq.push({dis[node_n][0],{node_n,0}});
                    }
                }
                if(type_n==1)
                {
                    if(weight+weight_n<dis[node_n][1])
                    {
                        dis[node_n][1]=weight+weight_n;
                        pq.push({dis[node_n][1],{node_n,1}});
                    }
                }
            }
        }
    }
    if(dis[D][0]==1e9 && dis[D][1]==1e9) return -1;
    return min(dis[D][0],dis[D][1]);
}