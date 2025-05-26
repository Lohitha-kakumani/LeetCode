class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int>freq;
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }
        for(int i=1; i<=n ;i++){
            if(freq[i] == 0 ) res.push_back(i);
        }
        return res;
    }
};