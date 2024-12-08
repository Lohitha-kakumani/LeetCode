class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        backtrack(s,0,0,"",result);
        return result;
    }
private:
    void backtrack(const string& s, int start, int segments, string current, vector<string>& result){
        if(segments == 4 && start == s.size()){
            result.push_back(current.substr(0, current.size() - 1));
            return;
        }

        if(segments == 4 || start == s.size()) return;

        for(int len = 1; len <= 3 && start + len <= s.size(); len++){
            string part = s.substr(start,len);
            if((part[0] == '0' && part.size() > 1) || stoi(part) > 255) continue;
            backtrack(s, start+len, segments+1, current+part+".", result);
        }
    }
};