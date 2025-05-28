class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> graph1(n), graph2(m);
        for (auto& e : edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }
        auto getCounts = [](const vector<vector<int>>& graph, int dist) {
            int sz = graph.size();
            vector<int> counts(sz, 0);
            for (int i = 0; i < sz; i++) {
                queue<pair<int,int>> q;
                vector<bool> visited(sz, false);
                q.push({i, 0});
                visited[i] = true;
                int cnt = 0;
                while (!q.empty()) {
                    auto [node, d] = q.front(); q.pop();
                    if (d > dist) continue;
                    cnt++;
                    for (int nei : graph[node]) {
                        if (!visited[nei]) {
                            visited[nei] = true;
                            q.push({nei, d + 1});
                        }
                    }
                }
                counts[i] = cnt;
            }
            return counts;
        };
        vector<int> count1 = getCounts(graph1, k);
        vector<int> count2 = getCounts(graph2, k - 1);
        int maxCount2 = 0;
        for (int c : count2) maxCount2 = max(maxCount2, c);
        vector<int> answer(n);
        for (int i = 0; i < n; i++) {
            answer[i] = count1[i] + maxCount2;
        }
        return answer;
    }
};