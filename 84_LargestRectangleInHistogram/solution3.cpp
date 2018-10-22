// Divide and conquer
// O(nlog(n)) -- worst case O(n^2). If the numbers in the array are sorted, we don't gain the advantage
// O(n) - recursion with worst case depth n

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return calculateArea(heights, 0, heights.size()-1);
    }
private:
    int calculateArea(vector<int>& heights, int start, int end){
        if(start > end) return 0;
        int minIndex = start;
        for(int i = start; i <= end; ++i){
            if(heights[i] < heights[minIndex]) minIndex = i;
        }
        return max(heights[minIndex] * (end-start+1), max(calculateArea(heights, start, minIndex-1), calculateArea(heights, minIndex+1, end)));
    }
};
