// O(nlogn) && O(n)

class Solution{
public:
    void wiggleSort(vector<int>& nums){
        if(nums.size() <= 1) return;
        sort(nums.begin(), nums.end());
        int len = nums.size(), k = 1, high = (len % 2) ? len - 1 : len - 2, mid = nums[len/2];
        for(int i = len-1; i >= 0 && nums[i] > mid; --i, k+=2)
            ans[k] = nums[i];
        for(int i = 0; i < len && nums[i] < mid; ++i, high-=2)
            ans[high] = nums[i];
        nums = ans;
    }
}

//O(n) && O(1)
void wiggleSort(vector<int>& nums){
    int n = nums.size();

    auto midptr = nums.begin() + n /2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    // i: locate numbers bigger than mid at odd index, from left to right
    // j: locate numbers less than mid at even index, from right to left
    int i = 1, j = n%2 ? n-1 : n-2, p = 0;

    while(p < n){
         // if current number is bigger than mid, and p>i (if p<= i, means that nums[p] already has been located) or p is even index. Then nums[p] needs to be located at i.
        if(nums[p] > mid && (p > i || p % 2 == 0)){
            swap(nums[p], nums[i]);
            i+=2;
        }else if(nums[p] < mid && (p < j || p % 2 == 1)){
            swap(nums[p], nums[j]);
            j-=2;
        }else ++p; // if nums[p] is equals to mid, or nums[p] has been located, skip it.
    }

}

