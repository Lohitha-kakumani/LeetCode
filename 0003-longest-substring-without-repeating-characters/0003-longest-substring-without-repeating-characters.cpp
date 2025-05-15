class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash; // stores char -> last index
        int left = 0; // left pointer of sliding window
        int maximum = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char ch = s[right];

            // If char seen before and its last index is >= left pointer,
            // move left pointer to last index + 1
            if (hash.find(ch) != hash.end() && hash[ch] >= left) {
                left = hash[ch] + 1;
            }

            hash[ch] = right; // update last index of char
            maximum = max(maximum, right - left + 1); // update max length
        }
        return maximum;
    }
};
