class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int> freq;
        for(int num : nums){
            freq[num]++;
        }
        for(auto& [num,count] : freq){
            if(count > n/3)
            res.push_back(num);
        }
        return res;
    }
};