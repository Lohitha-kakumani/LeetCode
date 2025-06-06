class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash; 
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (hash.find(num) != hash.end()) {
                if (i - hash[num] <= k)
                    return true;
            }
            hash[num] = i; 
        }
        return false;
    }
};