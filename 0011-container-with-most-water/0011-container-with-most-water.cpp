class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0,right = height.size()-1,maximum = 0;
       while(left <= right){
        int width = right - left;
        int area = min(height[left],height[right])*width;
        maximum = max(maximum,area);
        if(height[left] <= height[right]) left++;
        else right--;
       }
       return maximum;
    }
};