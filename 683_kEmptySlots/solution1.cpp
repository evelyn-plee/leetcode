/*
Time Complexity: O(n)
Space Complexity: O(n), to store which flower is open on each day
*/

#include <vector>
#include <math>

using namespace std;

class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k){
       int n = flowers.size();
       if(n == 0 || k >= n) return -1;
       
       vector<int> day(n, 0);
       for(int i = 0; i < n; i++){
           day[flowers[i]-1] = i+1;
       }

      int l = 0, r = k + 1, res = INT_MAX;
      for(int i = 0; r < n; i++){
          if(day[i] < day[l] || day[i] <= day[r]){
              if(i == r) res = min(res, max(day[l], day[r]));
              l = i;
              r = i + k + 1;
          }
      }
       return res == INT_MAX ? -1 : res;
    }
};
