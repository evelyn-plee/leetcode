// TC: O(n^2), SC: O(n)

class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T){
        int n = T.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            int j = i+1;
            while(j < n){
                if(T[j] > T[i]){
                    res[i] = j-i;
                    break;
                }
                j++;
            }
        }
        return res;
    }
}

// TODO: Find out the time complexity, SC: O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> toProcess;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++){
            while(toProcess.size() && T[i] > T[toProcess.top()]){
                res[toProcess.top()] = i - toProcess.top();
                toProcess.pop();
            }
            toProcess.push(i);
        }
        return res;
    }
};
