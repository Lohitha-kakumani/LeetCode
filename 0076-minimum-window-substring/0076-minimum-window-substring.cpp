class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char , int> targetFreq, windowFreq;
        for(char c : t) targetFreq[c]++;

        int left =0, right=0, minLen = INT_MAX, start =0;
        int matched =0;
        while(right < s.size()) {
            char c = s[right];
            windowFreq[c]++;

            if(targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
                matched++;
            }

            while(matched == targetFreq.size()) {
                if(right - left + 1 < minLen) {
                    minLen = right - left +1;
                    start = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;
                if(targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]) {
                    matched--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start,minLen);
    }
};