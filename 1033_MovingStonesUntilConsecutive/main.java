class Solution {
    public int[] numMovesStones(int a, int b, int c) {
        int x = Math.min(a, Math.min(b, c)), z = Math.max(a, Math.max(b, c)), y = a + b + c - x - z;
        if(x + 2 == z) return new int[]{0, 0};
        if(y - x <= 2 || z - y <= 2) return new int[]{1, z-x-2};
        return new int[]{2, z-x-2};
    }
}
