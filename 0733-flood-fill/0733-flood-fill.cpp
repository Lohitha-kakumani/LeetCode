class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];

        // Early return if the color is already the same
        if (originalColor == color) return image;

        queue<pair<pair<int,int>,int>> q;
        q.push({{sr, sc}, color});
        image[sr][sc] = color;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int r = q.front().first.first;
                int c = q.front().first.second;
                int co = q.front().second;
                q.pop();

                // Left
                if (c > 0 && image[r][c - 1] == originalColor) {
                    image[r][c - 1] = co;
                    q.push({{r, c - 1}, co});
                }
                // Right
                if (c < m - 1 && image[r][c + 1] == originalColor) {
                    image[r][c + 1] = co;
                    q.push({{r, c + 1}, co});
                }
                // Up
                if (r > 0 && image[r - 1][c] == originalColor) {
                    image[r - 1][c] = co;
                    q.push({{r - 1, c}, co});
                }
                // Down
                if (r < n - 1 && image[r + 1][c] == originalColor) {
                    image[r + 1][c] = co;
                    q.push({{r + 1, c}, co});
                }
            }
        }

        return image;
    }
};