class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int>nums;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                nums.push_back(grid[i][j]);
            }
        }
        int k = m*n;
        unordered_map<int,int> freq;
        int missing = -1, repeating = -1;
        for(int num : nums) freq[num]++;
        for(int i=1 ;i<=k; i++){
            if(freq[i] == 0) missing = i;
            if(freq[i] == 2) repeating = i;
        }
        return {repeating,missing};
    }
};