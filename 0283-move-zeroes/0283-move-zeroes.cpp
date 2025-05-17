class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int dummy =0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[dummy++] = nums[i];
            }
        }
        while(dummy < n){
            nums[dummy++] = 0;
        }
    }
};