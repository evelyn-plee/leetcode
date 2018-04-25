class Solution{
public:
    string countAndSay(int n){
        vector<char> buf1, buf2;
        vector<char> *pre = &buf1, *cur = &buf2;
        pre->push_back('1');

        while(--n){
          cur -> clear();
          char c = (*pre)[0];
          int count = 1;
          for(int i = 1; i < pre -> size(); ++i){
            if((*pre)[i] == c){
              count += 1;
            } else{
              append_int(*cur, count);
              cur -> push_back(c);
              c = (*pre)[i];
              count = 1;
            }
          }
          append_int(*cur, count);
          cur -> push_back(c);
          swap(pre, cur);
        }
        return string(pre->begin(), pre->end());
    }
private:
    void append_int(vector<char> &buf, int n){
      while (n!=0){
        buf.push_back('0' + n % 10);
        n /= 10;
      }
  }
};
