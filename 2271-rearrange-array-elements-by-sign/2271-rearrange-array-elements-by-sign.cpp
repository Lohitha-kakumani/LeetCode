class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(int i=0; i< nums.size();i++){
            if(nums[i] >= 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
            int posIndex= 0 ; 
            int negIndex = 0;
            int i=0;

            while(posIndex < pos.size() && negIndex < neg.size()){
                if(i%2 == 0){
                    nums[i++] = pos[posIndex++];
                }
                else{
                    nums[i++] = neg[negIndex++];
                }
            }

            while(posIndex < pos.size()){
                nums[i++] = pos[posIndex++];
            }
            while(negIndex < neg.size()){
                nums[i++] = neg[negIndex++];
            }
        return nums;
    }
};