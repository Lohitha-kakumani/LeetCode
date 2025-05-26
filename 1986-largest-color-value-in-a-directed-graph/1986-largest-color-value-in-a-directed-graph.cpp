class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int visited = 0;
        int result = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;

            int colorIndex = colors[node] - 'a';
            dp[node][colorIndex]++;

            result = max(result, dp[node][colorIndex]);

            for (int nei : graph[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return visited == n ? result : -1;
    }
};
