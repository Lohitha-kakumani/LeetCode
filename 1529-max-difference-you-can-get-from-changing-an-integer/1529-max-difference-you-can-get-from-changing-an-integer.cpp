class Solution {
public:
    int maxDiff(int num) {
         string s = to_string(num);
        
        // Create max version: replace first digit not 9 with 9
        string a = s;
        for (char c : s) {
            if (c != '9') {
                for (char &ch : a) {
                    if (ch == c) ch = '9';
                }
                break;
            }
        }
        string b = s;
        if (s[0] != '1') {
            char target = s[0];
            for (char &ch : b) {
                if (ch == target) ch = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char target = s[i];
                    for (char &ch : b) {
                        if (ch == target) ch = '0';
                    }
                    break;
                }
            }
        }
        return stoi(a) - stoi(b);
    }
};