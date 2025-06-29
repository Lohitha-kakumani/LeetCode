class Solution {
public:
    int hIndex(vector<int>& citations) {
        int count=0;
        sort(citations.begin(),citations.end());

        for(int i=0;i<citations.size();i++)
        {
            int len=citations.size()-i;
            count=max(min(len,citations[i]),count);
        }


        return count;
    }
};