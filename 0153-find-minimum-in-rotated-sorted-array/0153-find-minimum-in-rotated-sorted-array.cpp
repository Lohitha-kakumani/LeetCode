class Solution {
public:
    int findMin(vector<int>& nums) {
        int minval = nums[0];
        int left =0,right = nums.size()-1;
        while(left <= right){
            if(nums[left] < nums[right]){
                minval = min(minval,nums[left]);
                break;
            }

            int mid = (int)(left+right)/2;
            minval = min(minval,nums[mid]);

            if(nums[mid]>=nums[left]) left = mid+1;
            else right = mid - 1;
        }
        return minval;
    }
};