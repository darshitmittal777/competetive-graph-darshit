int Solution::solve(int A, vector<vector<int> > &B){
    vector<int>adj[A];
    for(int i=0;i<B.size();i++)
    {
        adj[B[i][0]-1].push_back(B[i][1]-1);
    }
    vector<int>reached(A,0);
    queue<int>q;
    q.push(0);
    reached[0] = 1;
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
            if(*it==(A-1))
            return true;
        }
    }
    return false;
}