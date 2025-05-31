class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        auto getCoordinates = [&](int s) {
            int row = (s - 1) / n;
            int col = (s - 1) % n;
            if (row % 2 == 1) col = n - 1 - col;
            row = n - 1 - row;
            return make_pair(row, col);
        };

        queue<int> q;
        vector<bool> visited(n * n + 1, false);
        q.push(1);
        visited[1] = true;
        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return moves;

                for (int dice = 1; dice <= 6 && curr + dice <= n * n; ++dice) {
                    int next = curr + dice;
                    auto [r, c] = getCoordinates(next);
                    if (board[r][c] != -1) {
                        next = board[r][c];
                    }
                    if (!visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};
