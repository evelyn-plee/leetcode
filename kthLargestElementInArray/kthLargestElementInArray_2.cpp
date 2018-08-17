class Solution{
public:
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int, vector<int>, greater<int>> topKNumbers;
        // min-priority-queue
        
        int len = nums.size();
        for(int i = 0; i < len; i++){
            int num = nums[i];
            
            if(topKNumbers.size() < k){
                topKNumbers.push(num);
            } else{
                if(num > topKNumbers.top()){
                    topKNumbers.push(num);
                    topKNumbers.pop();
                }
            }
        }
        return topKNumbers.top();
    }
};
