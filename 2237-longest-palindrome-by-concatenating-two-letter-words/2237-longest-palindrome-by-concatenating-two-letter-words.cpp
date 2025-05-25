class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int freq[26][26] = {};
        for (auto& word : words) {
            freq[word[0] - 'a'][word[1] - 'a']++;
        }

        int result = 0;
        bool centerUsed = false;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (i == j) {
                    int pairs = freq[i][i] / 2;
                    result += pairs * 4;
                    freq[i][i] -= pairs * 2;
                    // One can go to the center
                    if (!centerUsed && freq[i][i] > 0) {
                        result += 2;
                        centerUsed = true;
                    }
                } else if (i < j) {
                    // Pair "ab" with "ba"
                    int pairs = min(freq[i][j], freq[j][i]);
                    result += pairs * 4;
                }
            }
        }

        return result;
    }
};
