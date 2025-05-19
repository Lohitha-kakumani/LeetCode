class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int>even;
        vector<int>odd;
        for(int i=0; i<n; i++){
            if(i%2 == 0)even.push_back(nums[i]);
            else odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int j=0;
        int m = odd.size()-1;
        for(int i=0; i<n; i++){
            if(i%2==0){
                nums[i] = even[j];
                j++;
            }
            else{
                nums[i] = odd[m];
                m--;
            }
        }
        return nums;
    }
};