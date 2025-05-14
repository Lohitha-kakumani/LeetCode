class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>hash;
        for(int n:nums){
            if(hash.find(n) != hash.end()) return true;
            else{
                hash.insert(n);
            }
        }
        return false;
    }
};