class Solution{
public:
    void sink(vector<int>& heap, int i){
        while(true){
            int left = (i << 1) + 1;
            int right = (i << 1) + 2;
            int largest = i;
            if (left < heap.size() && heap[largest] < heap[left]) largest = left;
            if (right < heap.size() && heap[largest] < heap[right]) largest = right;
            if (i == largest) break;
            swap(heap[i], heap[largest]);
            i = largest;
        }
    }
    
    void make_heap(vector<int>& heap){
        for(int i = (heap.size()-2) >> 1; i >= 0; --i) sink(heap,i);
    }
    
    int findKthLargest(vector<int>& nums, int k){
        k = nums.size() - k + 1;
        vector<int> heap(nums.begin(), nums.begin() + k);
        make_heap(heap);
        
        for(int i = k; i < nums.size(); ++i){
            if(nums[i] < heap.front()){
                swap(heap.front(), nums[i]);
                sink(heap, 0);
            }
        }
        return heap.front();
    }
};
