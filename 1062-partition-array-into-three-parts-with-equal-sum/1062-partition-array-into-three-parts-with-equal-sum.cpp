class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum += arr[i];
        }
        if(sum % 3 != 0)return false;
        int target = sum/3,current=0,count=0;
        for(int i=0; i<n; i++){
            current = current+arr[i];
            if(current == target){
                count++;
                current =0;
            }
        }
        return count >= 3;
    }
};