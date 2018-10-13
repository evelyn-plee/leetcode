/**
* Time complexity: O(n); Space complexity: O(1)
**/


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int curMax = 0;
        for(int i = 0; i < arr.size(); ++i){
            curMax = max(curMax, arr[i]);
            if(curMax == i) ++ans;
        }
        return ans;
    }
};
