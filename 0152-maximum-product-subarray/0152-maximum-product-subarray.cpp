class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int current = nums[0];
        int minimum = nums[0];
        int maximum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i] < 0) swap(maximum,minimum);
            maximum = max(nums[i],maximum*nums[i]);
            minimum = min(nums[i],minimum*nums[i]);
            current = max(maximum,current);
        }
        return current;
    }
};