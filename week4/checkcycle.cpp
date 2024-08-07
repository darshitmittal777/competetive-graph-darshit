class Solution {
public:
    int checkDFS(vector<vector<char>>& grid, int x, int y, int px, int py, vector<vector<int>>& vis,int s=1,int mx=0) {
        vis[x][y] = 1;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == grid[x][y]) {
                if (nx == px && ny == py)
                    continue;
                if (vis[nx][ny] == 1)
                    mx = max(s+1,mx);
                if (vis[nx][ny] == 0 )
                    checkDFS(grid, nx, ny, x, y, vis,s+1,mx);
            }
        }
        vis[x][y] = 2;
        
        return mx;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        
        int mx = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (vis[i][j] == 0)
                    mx = max(mx,checkDFS(grid, i, j, -1, -1, vis));
            }
        }
        return mx;
    }
};
