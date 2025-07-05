class Solution {
public:
    int findLucky(vector<int>& arr) {
        int count =0;
        unordered_map<int,int>freq;
        for (int num : arr) {
            freq[num]++;
        }
        int result = -1;

        for (auto& pair : freq) {
            if (pair.first == pair.second) {
                result = max(result, pair.first);  // get the largest lucky integer
            }
        }

        return result;
    }
};