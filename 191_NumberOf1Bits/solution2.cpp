// O(1), O(1)
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int sum = 0;
        while(n != 0){
            ++sum;
            // flip the least significant bit
            n &= (n-1);
        }
        return sum;
    }
};
