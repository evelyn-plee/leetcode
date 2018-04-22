class Solution{
public:
    vector<int> plusOne(vector<int>& digits){
      int carry = 1;
      for(int i = digits.size() - 1; i>=0; i--){
        digits[i] += carry;
        if(digits[i] == 10){
          digits[i] = 0;
          carry = 1;
        } else carry = 0;
      }
      if (carry) digits.insert(digits.begin(), carry);
      return digits;
    }
};
