class Solution {
public:
//the minimum insertion steps is the total string length - the longest palindromic subsequence
    // Helper function to calculate longest palindromic subsequence length
    int longestPalindromicSubseq(string s) {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i-1] == rev[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][n]; // length of LPS
    }

    // Main function to return min insertions to make palindrome
    int minInsertions(string s) {
        int n = s.size();
        return n - longestPalindromicSubseq(s);
    }
};
