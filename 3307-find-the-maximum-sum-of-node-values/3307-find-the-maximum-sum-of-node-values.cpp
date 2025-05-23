class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
         long long total_sum = 0;
        int positive_gain_count = 0;
        int min_gain = INT_MAX;

        for (int num : nums) {
            int xor_val = num ^ k;
            if (xor_val > num) {
                positive_gain_count++;
                total_sum += xor_val;
                min_gain = std::min(min_gain, xor_val - num);
            } else {
                total_sum += num;
                min_gain = std::min(min_gain, num - xor_val);
            }
        }

        if (positive_gain_count % 2 == 0) {
            return total_sum;
        } else {
            return total_sum - min_gain;
        }
    }
};