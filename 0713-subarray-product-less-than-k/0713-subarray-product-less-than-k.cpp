class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int count=0,start=0,end=0,product=1;
        int n = nums.size();
        while(end < n){
            product = product*nums[end];
            while(product >= k){
                product = product / nums[start];
                start++;
            }
            count += (end-start+1);
            end++;
        }
        return count;
    }
};