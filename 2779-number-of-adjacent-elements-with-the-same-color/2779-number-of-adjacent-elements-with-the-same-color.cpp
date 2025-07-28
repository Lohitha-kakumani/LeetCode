class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> colors(n, 0);
        vector<int> result;
        int count = 0;
        
        for (auto& q : queries) {
            int i = q[0], c = q[1];
            if (colors[i] != 0) {
                if (i > 0 && colors[i] == colors[i - 1]) count--;
                if (i < n - 1 && colors[i] == colors[i + 1]) count--;
            }
            colors[i] = c;
            if (i > 0 && colors[i] == colors[i - 1]) count++;
            if (i < n - 1 && colors[i] == colors[i + 1]) count++;
            result.push_back(count);
        }
        
        return result;
    }
};
