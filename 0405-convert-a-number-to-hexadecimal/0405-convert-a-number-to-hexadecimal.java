class Solution {
    public String toHex(int num) {
        if (num == 0)
            return "0";
        StringBuilder sb = new StringBuilder();
        while (num != 0) {
            int digit = num & 15;
            sb.append(calculate(digit));
            num = num >>> 4;
        }
        return sb.reverse().toString();
    }

    char calculate(int digit) {
        if (digit == 10)
            return 'a';
        else if (digit == 11)
            return 'b';
        else if (digit == 12)
            return 'c';
        else if (digit == 13)
            return 'd';
        else if (digit == 14)
            return 'e';
        else if (digit == 15)
            return 'f';
        else
            return (char) ('0' + digit);
    }
}