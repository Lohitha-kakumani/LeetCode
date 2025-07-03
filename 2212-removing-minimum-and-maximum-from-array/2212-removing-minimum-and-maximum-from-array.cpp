class Solution {
public:
    int minimumDeletions(vector<int>& n) {
    auto [it1, it2] = minmax_element(begin(n), end(n));
    int i = min(it1, it2) - begin(n), j = max(it1, it2) - begin(n);
    return min({ j + 1, (int)n.size() - i, i + 1 + (int)n.size() - j });
}
};