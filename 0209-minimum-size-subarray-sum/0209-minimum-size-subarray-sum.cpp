class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(),l=0,s=0,m=INT_MAX;
        for(int i=0;i<n;i++){
            s += nums[i];
            while(s>=target){
                m = min(m,i-l+1);
                s -= nums[l];
                l++;
            }
        }
        return (m==INT_MAX)?0:m;
    }
};