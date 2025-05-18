class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<int>> validCols;
    unordered_map<int, vector<int>> compat;

    void generateValidCols(int pos, int prevColor, int code, vector<int>& col) {
        if (pos == m) {
            validCols.push_back(col);
            return;
        }
        for (int color = 0; color < 3; ++color) {
            if (color != prevColor) {
                col[pos] = color;
                generateValidCols(pos + 1, color, code * 3 + color, col);
            }
        }
    }

    bool isCompatible(vector<int>& a, vector<int>& b) {
        for (int i = 0; i < m; ++i)
            if (a[i] == b[i]) return false;
        return true;
    }

    int paintingTheGrid(int M, int N) {
        m = M, n = N;
        vector<int> col(m);
        generateValidCols(0, -1, 0, col);

        int sz = validCols.size();
        unordered_map<int, vector<int>> encodedCol;
        unordered_map<string, int> decodeToIndex;

        for (int i = 0; i < sz; ++i) {
            string key = "";
            for (int c : validCols[i]) key += to_string(c);
            decodeToIndex[key] = i;
        }

        vector<vector<int>> compatible(sz);
        for (int i = 0; i < sz; ++i)
            for (int j = 0; j < sz; ++j)
                if (isCompatible(validCols[i], validCols[j]))
                    compatible[i].push_back(j);

        vector<long long> dp(sz, 1);

        for (int col = 1; col < n; ++col) {
            vector<long long> new_dp(sz, 0);
            for (int i = 0; i < sz; ++i) {
                for (int prev : compatible[i]) {
                    new_dp[i] = (new_dp[i] + dp[prev]) % MOD;
                }
            }
            dp = new_dp;
        }

        long long result = 0;
        for (long long val : dp) result = (result + val) % MOD;
        return result;
    }

    int colorTheGrid(int m, int n) {
        return paintingTheGrid(m, n);
    }
};
