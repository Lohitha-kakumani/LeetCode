class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        if(n==2) return 0;

        int esum=0,osum=0,res=0;
        for(int i=0; i<n; i++){
            (i%2 ? osum : esum) += nums[i];
        }

        int oIdx=0, eIdx=0;
        for(int i=0; i<n; i++){
            if(i%2 == 0) oIdx -= nums[i];
            else eIdx -= nums[i];

            if(eIdx + osum == oIdx + esum) res++;

            if(i%2 == 0) eIdx += nums[i];
            else oIdx += nums[i];
        }
        return res;
    }
};