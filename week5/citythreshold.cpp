class Solution {
public:
   int findMin(vector<int>& vec) {
        int minElement = INT_MAX;
        int index = -1;
        for (int i = 0; i < vec.size(); ++i) {
            if (vec[i] < minElement || (vec[i] == minElement && i > index)) {
                minElement = vec[i];
                index = i;
            }
        }
        return index;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distT) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int from = edge[0],to = edge[1],weight = edge[2];
            graph[from].emplace_back(to, weight);
            graph[to].emplace_back(from, weight); 
        }

        vector<int> paths(n, 0);
        for (int i = 0; i < n; i++) {
            queue<pair<int, int>> q; 
            vector<int> distances(n, INT_MAX);

            q.emplace(i, 0);
            distances[i] = 0;

            while (!q.empty()) {
                auto [currentCity, currentDist] = q.front();
                q.pop();

                if (currentDist > distT) continue;

                for (const auto& [nextCity, weight] : graph[currentCity]) {
                    int newDist = currentDist + weight;
                    if (newDist < distances[nextCity]) {
                        distances[nextCity] = newDist;
                        q.emplace(nextCity, newDist);
                    }
                }
            }

            for (int j = 0; j < n; j++) {
                if (i != j && distances[j] <= distT) {
                    paths[i]++;
                }
            }
        }
        return findMin(paths);
    }
};