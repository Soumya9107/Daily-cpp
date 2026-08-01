class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int maxWater = 0;
        while(left < right){
            int w = right - left;
            int h = min(heights[left],heights[right]);
            int area = w*h;
            maxWater = max(area, maxWater);
                if(heights[left] < heights[right]){
                    left++;
                }
                else if(heights[right] < heights[left]){
                    right--;
                }
                else{
                    left++;
                    right--;
                }
            }
            return maxWater;
        }
};
