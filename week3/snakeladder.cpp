
int Solution::snakeLadder(vector<vector<int>>& A, vector<vector<int>>& B) {
    unordered_map<int, int> ladderMap, snakeMap;
    vector<int> visited(101, 0);
    queue<pair<int, int>> q;
    
    for (const auto& ladder : A)
        ladderMap[ladder[0]] = ladder[1];
    
    for (const auto& snake : B)
        snakeMap[snake[0]] = snake[1];
    
    q.push({0, 1});
    visited[1] = 1;
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        
        for (int i = 1; i <= 6; ++i) {
            int nextPos = current.second + i;
            if (nextPos > 100)
                break;
            
            if (ladderMap.find(nextPos) != ladderMap.end())
                nextPos = ladderMap[nextPos];
            else if (snakeMap.find(nextPos) != snakeMap.end())
                nextPos = snakeMap[nextPos];
            
            if (nextPos == 100)
                return current.first + 1;
            
            if (!visited[nextPos]) {
                q.push({current.first + 1, nextPos});
                visited[nextPos] = 1;
            }
        }
    }
    
    return -1; // No solution found
}