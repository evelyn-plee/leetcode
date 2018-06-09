class Solution{
public:
    int hammingWeight(unit32_t n){
        return bitset<32>(n).count();
    }
};