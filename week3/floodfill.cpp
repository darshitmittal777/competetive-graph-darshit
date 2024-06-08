class Solution {
public:
    void fill(vector<vector<int>>& image, int x, int y, int color, int match, vector<vector<int>>& check) {
        image[x][y] = color;
        check[x][y] = 1;
        
        int rows = image.size();
        int cols = image[0].size();
        
        if (x - 1 >= 0 && check[x - 1][y] == 0 && image[x - 1][y] == match) {
            fill(image, x - 1, y, color, match, check);
        }
        if (y - 1 >= 0 && check[x][y - 1] == 0 && image[x][y - 1] == match) {
            fill(image, x, y - 1, color, match, check);
        }
        if (x + 1 < rows && check[x + 1][y] == 0 && image[x + 1][y] == match) {
            fill(image, x + 1, y, color, match, check);
        }
        if (y + 1 < cols && check[x][y + 1] == 0 && image[x][y + 1] == match) {
            fill(image, x, y + 1, color, match, check);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> check(image.size(), vector<int>(image[0].size(), 0));
        fill(image, sr, sc, color, image[sr][sc], check);
        return image;
    }
};
