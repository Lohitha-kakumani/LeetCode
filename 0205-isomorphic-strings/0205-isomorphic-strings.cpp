class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sMap, tMap;
        for (int i = 0; i < s.size(); ++i) {
            char sc = s[i], tc = t[i];
            if ((sMap.count(sc) && sMap[sc] != tc) ||
                (tMap.count(tc) && tMap[tc] != sc)) {
                return false;
            }

            sMap[sc] = tc;
            tMap[tc] = sc;
        }

        return true;
    }
};