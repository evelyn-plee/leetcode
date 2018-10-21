class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int lProduct = 1, rProduct = 1;
        int size = nums.size(), maxProduct = nums[0];
        for(int i = 0; i < size; ++i)
        {
            lProduct *= nums[i];
            rProduct *= nums[size-i-1];
            maxProduct = max(maxProduct, max(lProduct, rProduct));
            if(lProduct == 0) lProduct = 1;
            if(rProduct == 0) rProduct = 1;
        }
        return maxProduct;
    }
};
