class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(int i=0 ; i<nums.size(); i++){
            int x = nums[i];
            if(hash.find(x) != hash.end()){
                return x;
            }
            hash.insert(x);
        }
        return -1;
    }
};