class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        auto replaceDigits = [](string str, char fromDigit, char toDigit) {
            for (char &c : str) {
                if (c == fromDigit) c = toDigit;
            }
            return str;
        };
        
        // Max number: replace first non-'9' digit with '9'
        string maxStr = s;
        char maxFrom = ' ';
        for (char c : s) {
            if (c != '9') {
                maxFrom = c;
                break;
            }
        }
        if (maxFrom != ' ') maxStr = replaceDigits(s, maxFrom, '9');
        
        // Min number: replace first non-'0' digit with '0'
        string minStr = s;
        char minFrom = ' ';
        for (char c : s) {
            if (c != '0') {
                minFrom = c;
                break;
            }
        }
        if (minFrom != ' ') minStr = replaceDigits(s, minFrom, '0');
        
        return stoi(maxStr) - stoi(minStr);
    }
};