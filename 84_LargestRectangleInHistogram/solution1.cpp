// BruteForce: O(n^3), find minimum height bar O(n) lying between every pair O(n^2)
// Space complexity: O(1)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i = 0; i < heights.size(); ++i){
            for(int j = i; j < heights.size(); ++j){
                int minHeight = INT_MAX;
                for(int k = i; k <= j; ++k){
                    minHeight = min(minHeight, heights[k]);
                }
                maxArea = max(maxArea, minHeight * (j-i+1));
            }
        }
        return maxArea;
    }
};
