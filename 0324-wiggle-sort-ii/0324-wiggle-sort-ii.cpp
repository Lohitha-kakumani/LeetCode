class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int n = nums.size();
        int mid = (n + 1) / 2;
        int end = n;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = temp[--mid]; 
            } else {
                nums[i] = temp[--end]; 
            }
        }
    }
};
