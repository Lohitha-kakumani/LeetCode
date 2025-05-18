class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res=0;
        int start =0,end=0;
        int count=0;
        while(end<nums.size()){
            if(nums[end] == 0)
            count++;

            while(count > k){
                if(nums[start] == 0) count--;
                start++;
            }

            res = max(res,end-start+1);

            end++;
        }
        return res;
    }
};