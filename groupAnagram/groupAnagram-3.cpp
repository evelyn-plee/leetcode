class Solution{
private:
    bool isPrime(int n){
        int rt = sqrt((float)n);
        for(int i = 2; i <= rt; i++){
            if(n % i == 0) return false;
        }
        return true;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string>& strs){
        vector<int> prime;
        int c = 2;
        for(int i = 0; i < 26; i++){
            while(!isPrime(c)) c++;
            prime.push_back(c++);
        }

        vector<vector<string>> res;
        map<int, vector<string>> mp;
        for(auto &str: strs){
            int tmp = 1;
            for(int i = 0; i < str.size(); i++) tmp *= prime[str[i]-'a'];
            mp[tmp].push_back(str);
        }

        for(auto &m : mp) res.push_back(m.second);
        return res;
    }
};
