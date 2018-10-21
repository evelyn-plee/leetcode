// O(nk), for each int x, we need O(k) operations where k is the # of bits in int x
// O(n)

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        for(int i = 0; i <= num; ++i){
            res[i] = popCount(i);
        }
        return res;
    }
private:
    int popCount(int x){
        int count;
        for(count = 0; x != 0; ++count) x &= x-1;
        return count;
    }
};
