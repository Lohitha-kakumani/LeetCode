class Solution {
public:
    void send(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        send(grid,i+1,j,m,n);
        send(grid,i,j+1,m,n);
        send(grid,i-1,j,m,n);
        send(grid,i,j-1,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == '1'){
                    send(grid,i,j,m,n);
                    ans++;
                }
            }
        }
        return ans;
    }
};