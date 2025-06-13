class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int>dp(n,0),prev(n,0);
       
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(obstacleGrid[i][j]==1) dp[j]=0;
                else if(i==0 && j==0)dp[j]=1;
                else dp[j] = (j>0?dp[j-1]: 0) + prev[j];

            prev=dp;
        }

        return dp[n-1];
    }
};