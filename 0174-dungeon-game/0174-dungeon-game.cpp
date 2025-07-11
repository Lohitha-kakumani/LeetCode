class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1)
                    dp[i][j] = dungeon[i][j];                
                else if(i==n-1)
                    dp[i][j] = dungeon[i][j] + dp[i][j+1];                  
                else if( j==m-1)
                    dp[i][j] = dungeon[i][j] + dp[i+1][j];  
                else
                    dp[i][j] = dungeon[i][j] + max(dp[i+1][j], dp[i][j+1]);   
                if(dp[i][j]>0)
                    dp[i][j] = 0;
            }
        }
        if(dp[0][0]>=0)
            return 1;
        else 
            return (abs(dp[0][0])+1);
    }
};