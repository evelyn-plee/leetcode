// if one side is connected
// the smallest move will be moving the furthest stone
// the biggest move will be taking one step at a time and it will y-x-1 + z-y-1 -> z+y-y-x-1-1 -> z - x - 2
// otherwise
// the smallest move will be moving the leftmost to the left of y, and rightmost to the right of y
// the biggest move remain the same

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x = min(a, min(b, c)), z = max(a, max(b, c)), y = a + b + c - x - z;
        if(x + 2 == z) return {0, 0};
        if(y-x <= 2 || z-y <= 2) return {1, z-x-2};
        return {2, z-x-2};
    }
};
