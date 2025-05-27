class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += gain[i];
            gain[i] = sum;
        }
        int maximum = INT_MIN;
        for(int i=0; i<n; i++){
            int result = gain[i];
            maximum = max(result,maximum);
        }
        return (maximum > 0 ? maximum : 0);
    }
};