class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowel = 0, currVowel = 0;
        unordered_set<char> vowels = {'a','e','i','o','u'};
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) currVowel++;
        }
        maxVowel = currVowel;

        for (int i = k; i < s.size(); i++) {
            if (vowels.count(s[i])) currVowel++;
            if (vowels.count(s[i - k])) currVowel--;
            maxVowel = max(maxVowel, currVowel);
        }

        return maxVowel;
    }
};
