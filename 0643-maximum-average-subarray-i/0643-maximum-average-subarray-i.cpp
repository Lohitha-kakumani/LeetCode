class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int p1=0,p2=k;
        int sum=0;
        for(int i=p1; i<p2; i++){
            sum += nums[i];
        }
        int max = sum;
        while(p2 < nums.size()){
            sum += (nums[p2] - nums[p1]); //ekkada manam nums[p2] add chesi nums[p1] ni pikestunnam anaga dobbestunnam so this is a shorthand notation lohiiiiiiiiii
            if(sum > max) max = sum;
            p1++;
            p2++;
        }
        return (double) max/k;
    }
};