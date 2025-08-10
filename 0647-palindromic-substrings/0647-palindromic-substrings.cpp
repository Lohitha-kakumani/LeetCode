class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int center = 0; center < n; center++) {
            expandFromCenter(s, center, center, count);
            expandFromCenter(s, center, center + 1, count);
        }
        return count;
    }

private:
    void expandFromCenter(string& s, int left, int right, int& count) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
};
