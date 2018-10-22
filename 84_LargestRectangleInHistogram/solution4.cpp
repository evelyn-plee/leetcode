// O(n), n numbers are pushed and popped
// O(n)

class Solution{
public:
    int largestRectangleArea(vector<int>& height){
        int n = height.size();
        int maxArea = 0, h, l;
        stack<int> indexes;
        for(int i = 0; i <= n; ++i){
            while(i == n || (!indexes.empty() && height[indexes.top()] > height[i])){
                if(i == n && indexes.empty()){
                    h = 0; i++;
                }
                else{
                    h = height[indexes.top()];
                    indexes.pop();
                }
                l = indexes.empty() ? -1 : indexes.top();
                maxArea = max(maxArea, h * (i-l-1));
            }
            indexes.push(i);
        }
        return maxArea;
    }
};
