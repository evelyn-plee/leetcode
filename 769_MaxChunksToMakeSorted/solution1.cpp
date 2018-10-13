/**
* Time complexity: O(nlogn); Space complexity: O(n)
**/

class Solution{
public:
    int maxChunksToSorted(vector<int>& arr){
        int ans = 0;
        set<int> s;
        for(int i = 0; i < arr.size(); ++i){
            s.insert(arr[i]);
            if(*s.rbegin() == i) ++ans;
        }
        return ans;
    }
};
