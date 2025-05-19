class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int numofones = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) numofones++;
        }
        if(numofones == 0 || numofones == n) return 0;
        int x = numofones;
        int countones=0,maxones=0;
        vector<int> arr(nums.begin(),nums.end());
        arr.insert(arr.end(), nums.begin(), nums.end());

        for(int i=0; i<x;i++){
            if(arr[i] ==1)countones++;
        }
        maxones = countones;
        for(int i=1;i<=n;i++){
            if(arr[i-1] == 1) countones--;
            if(arr[i+x-1]==1) countones++;
            if(maxones < countones) maxones = countones;
        }
        int numofzeros = x-maxones;
        return numofzeros;
    }
};