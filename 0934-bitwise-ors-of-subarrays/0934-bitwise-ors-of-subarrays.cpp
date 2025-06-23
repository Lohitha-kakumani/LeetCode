class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
    set<int> sec, dp_set;
        dp_set.insert(0);
        for (int i = 0; i < arr.size(); i++) {
            set<int> temp;
            temp.insert(arr[i]);
            for (auto n : dp_set) {
                temp.insert(arr[i] | n);
            }
            dp_set = temp;
            sec.insert(dp_set.begin(), dp_set.end());
        }
        
        return sec.size();   
    }
};