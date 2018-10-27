// 12 * 6 * 2 * 4 * 4 * 4 = 9216 possibilities
// we choose two numbers (with order) in 12 ways and perform one of 4 operations (12 * 4). 
// Then, with 3 remaining numbers, we choose 2 of them and perform one of 4 operations (6 * 4). 
// Finally we have two numbers left and make a final choice of 2 * 4 possibilities.
// O(1), O(1)

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        do{
            if(valid(nums)) return true;
        } while(next_permutation(nums.begin(), nums.end()));
        return false;
    }
private:
    bool valid(vector<int>& nums){
        double a = nums[0], b = nums[1], c = nums[2], d = nums[3];
        if(valid(a+b, c, d) || valid(a-b, c, d) || valid(a*b, c, d) || valid(a/b, c, d)) return true;
        if(valid(a, b+c, d) || valid(a, b-c, d) || valid(a, b*c, d) || valid(a, b/c, d)) return true;
        if(valid(a, b, c+d) || valid(a, b, c-d) || valid(a, b, c*d) || valid(a, b, c/d)) return true;
        return false;
    }
    bool valid(double a, double b, double c){
        if (valid(a+b, c) || valid(a-b, c) || valid(a*b, c) || b&&valid(a/b, c)) return true;
        if (valid(a, b+c) || valid(a, b-c) || valid(a, b*c) || c&&valid(a, b/c)) return true;
        return false;
    }
    bool valid(double a, double b) {
        if (abs(a+b-24.0) < 0.0001 || abs(a-b-24.0) < 0.0001 || abs(a*b-24.0) < 0.0001 || b&&abs(a/b-24.0) < 0.0001) 
            return true;
        return false;
    }
};
