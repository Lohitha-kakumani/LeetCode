class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for(auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] += 1;
            if (r + 1 < n) diff[r + 1] -= 1;
        }

        vector<int> count(n, 0);
        count[0] = diff[0];
        for(int i = 1; i < n; ++i) {
            count[i] = count[i - 1] + diff[i];
        }
        
        for(int i = 0; i < n; ++i) {
            if(count[i] < nums[i]) return false;
        }
        return true;
    }
};