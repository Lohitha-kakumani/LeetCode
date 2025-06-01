class Solution {
public:
    long long combinations(int s) {
        if (s < 0) return 0;
        return 1LL * (s + 2) * (s + 1) / 2;
    }
    long long distributeCandies(int n, int limit) {
        int L = limit + 1;
        long long total = combinations(n);
        long long subtract1 = 3 * combinations(n - L);
        long long add2 = 3 * combinations(n - 2 * L);
        long long subtract3 = combinations(n - 3 * L);

        return total - subtract1 + add2 - subtract3;
    }
};
