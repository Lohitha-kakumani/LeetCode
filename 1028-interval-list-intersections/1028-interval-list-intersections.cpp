class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
     vector<vector<int>>res;
     vector<int>temp(2);
     int firstptr=0,secoondptr=0;
     int m = firstList.size();
     int n = secondList.size();
     while(firstptr < m && secoondptr < n){
        if(secondList[secoondptr][0] <= firstList[firstptr][1] && firstList[firstptr][0] <= secondList[secoondptr][1] ){
            temp[0] = max(firstList[firstptr][0],secondList[secoondptr][0]);
            temp[1] = min(firstList[firstptr][1],secondList[secoondptr][1]);
            res.push_back(temp);
        }
        if(firstList[firstptr][1] < secondList[secoondptr][1]) firstptr++;
        else secoondptr++;
     }
     return res;
    }
};