class Solution {
  public boolean canTransform(String start, String end) {
    if (start.length() != end.length()) {
      return false;
    }
    char[] s = start.toCharArray(), e = end.toCharArray();
    int i = 0, j = 0, len = s.length;
    
    while (i < len && j < len) {
      while (i < len && s[i] == 'X') {
        i++;
      }
      while (j < len && e[j] == 'X') {
        j++;
      }
      if (i >= len && j >= len) {
        return true;
      }
      if (i >= len || j >= len) {
        return false;
      }
      // [index1] = [index2] or XL -> LX or RX -> XR will return true
      if (s[i] != e[j] || s[i] == 'L' && i < j || s[i] == 'R' && i > j) {
        return false;
      }
      i++;
      j++;
    }
    return true;
  }
}
