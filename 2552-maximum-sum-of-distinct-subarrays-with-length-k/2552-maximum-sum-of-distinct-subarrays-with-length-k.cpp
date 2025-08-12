class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    long long windowSum = 0, maxSum = 0;

    int left = 0;
    for (int right = 0; right < nums.size(); right++) {
        freq[nums[right]]++;
        windowSum += nums[right];

        if (right - left + 1 > k) {
            freq[nums[left]]--;
            windowSum -= nums[left];
            if (freq[nums[left]] == 0) freq.erase(nums[left]);
            left++;
        }

        if (right - left + 1 == k && freq.size() == k) {
            maxSum = max(maxSum, windowSum);
        }
    }
    return maxSum;
}
};