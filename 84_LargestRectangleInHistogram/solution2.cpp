//O(n^2), O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i = 0; i < heights.size(); ++i){
            int minHeight = INT_MAX;
            for(int j = i; j < heights.size(); ++j){
                minHeight = min(minHeight, heights[j]);
                maxArea = max(maxArea, minHeight * (j-i+1));
            }
        }
        return maxArea;
    }
};
