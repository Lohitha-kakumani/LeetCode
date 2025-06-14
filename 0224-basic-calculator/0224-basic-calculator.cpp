class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int result = 0, sign = 1, num = 0;
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = ch - '0';
                while (i + 1 < s.length() && isdigit(s[i + 1])) {
                    num = num * 10 + (s[++i] - '0');
                }
                result += sign * num;
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
        }
        return result;
    }
};