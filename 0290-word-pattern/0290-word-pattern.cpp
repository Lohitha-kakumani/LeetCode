class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        istringstream iss(s);
        vector<string> words;
        string word;
        // Split string s into words
        while (iss >> word) {
            words.push_back(word);
        }

        if (words.size() != pattern.size()) return false;

        for (int i = 0; i < pattern.size(); ++i) {
            char c = pattern[i];
            string w = words[i];
            if ((charToWord.count(c) && charToWord[c] != w) ||
                (wordToChar.count(w) && wordToChar[w] != c)) {
                return false;
            }
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};
