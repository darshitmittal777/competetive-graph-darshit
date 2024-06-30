class Solution
{
	public:
	//Function to find the level of node X.
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
                return(check[*i]);
            }
        }
        return(-1);
	}
};