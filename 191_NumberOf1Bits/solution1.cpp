// depends on # of bits in n, because n here is a 32 bit integer, so time complexity: O(1)
// O(1)

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        int mask = 1;
        for(int i = 0; i < 32; i++){
            if((n & mask) != 0) ++bits;
            mask <<= 1;
        }
        return bits;
    }
};
