/* Use BST
* Time Complexity: O(nlogn) 
* Space Compexity: O(logn)
*/

class Solution{
public:
    int kEmptySlots(vector<int>& flowers, int k){
       int n = flowers.size();
       if(n == 0 || k >= n) return -1;
       
       set<int> xs;
       for(int i = 0; i < n; ++i){
           int x = flowers[i];
           // return pos where the element can be inserted
           auto r = xs.insert(x).first;
           auto l = r;
           if(++r != xs.end() && *r == x + k + 1) return i + 1;
           if(l != xs.begin() && *(--l) == x - k - 1) return i + 1;
       }
       return -1;
    }
};
