class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        int total = (n*(n+1))/2;
        for(int i=0 ; i<n; i++){
            sum = sum + nums[i];
        }
        int res = total - sum;
        return res;
    }
};