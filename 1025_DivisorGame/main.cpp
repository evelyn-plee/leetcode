class Solution {
public:
    bool divisorGame(int N) {
        memo_ = vector<int>(N+1, -1);
        return canWin(N);
    }    

private:
    vector<int> memo_;
    
    bool canWin(int N){
        if(N == 1) return false;
        if(memo_[N] != -1) return memo_[N];
        bool win = false;
        for(int i = 1; i < N; i++){
            if(N % i == 0) win |= !canWin(N-i);
        }
        return memo_[N] = win;
    }
};
