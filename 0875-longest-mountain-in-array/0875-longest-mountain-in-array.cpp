class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int i = 1; i < n - 1; ){
            if(arr[i] > arr[i - 1] && arr[i] > arr[i + 1]){
                int count = 1;
                int j = i;
                while(j > 0 && arr[j] > arr[j - 1]){
                    count++;
                    j--;
                }
                int k = i;
                while(k < n - 1 && arr[k] > arr[k + 1]){
                    count++;
                    k++;
                }
                ans = max(ans, count);
                i = k;
            } else {
                i++;
            }
        }
        return ans;
    }
};
