class Solution {
public:
#define equation(x,a,b,c) (a*x+b)*x+c
  vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    if (nums.empty()) return vector<int>();
    int n = nums.size();
    vector<int> res(n);
    int l = 0, r = n - 1;
    if (a < 0) {
      int i = 0;
      while (l <= r) {
        int x = equation(nums[r],a,b,c);
        int y = equation(nums[l],a,b,c);
        if (x < y) {
          res[i++] = x; r--;
        } else {
          res[i++] = y; l++;
        }
      }
    } else {
      int i = n - 1;
      while (l <= r) {
        int x = equation(nums[r],a,b,c);
        int y = equation(nums[l],a,b,c);
        if (x > y) {
          res[i--] = x; r--;
        } else {
          res[i--] = y; l++;
        }
      }
    }
    return res;
  }
};
