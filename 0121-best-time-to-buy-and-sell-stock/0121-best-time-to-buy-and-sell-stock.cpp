class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0,right = 1,maximum =0;
        while(right < prices.size()){
            if(prices[left]<prices[right]){
                int profit = prices[right]-prices[left];
                maximum = max(profit,maximum);
                right++;
            }
            else{
                left = right;
                right++;
            }
        }
        return maximum;
    }
};