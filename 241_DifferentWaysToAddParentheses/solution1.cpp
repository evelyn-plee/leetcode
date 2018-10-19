namespace signs{
    int add(int a, int b) {return a + b;}
    int minus(int a, int b) {return a - b;}
    int multiply(int a, int b) {return a * b;}
}

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        if(m_.count(input)) return m_[input];
        
        vector<int> res;
        
        for(int i = 0; i < input.length(); ++i){
            char op = input[i];
            if(op == '+' || op == '-' || op == '*'){
                const string left = input.substr(0, i);
                const string right = input.substr(i+1);
                const vector<int>& l = diffWaysToCompute(left);
                const vector<int>& r = diffWaysToCompute(right);
                
                std::function<int(int,int)>f;
                switch(op){
                    case '+' : f = signs::add; break;
                    case '-' : f = signs::minus; break;
                    case '*' : f = signs::multiply; break;
                }
                for(int a : l){
                    for(int b : r){
                        res.push_back(f(a,b));
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(input));
        }
        // memorize the ans for input
        m_[input].swap(res);
        return m_[input];  
    }
private:
    unordered_map<string, vector<int>> m_;
};
