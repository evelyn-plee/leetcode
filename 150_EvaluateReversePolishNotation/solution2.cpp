class Solution{
public:
    int evalRPN(vector<string>& tokens) {
        string s = tokens.back(); tokens.pop_back();
        
        if(s != "+" && s != "-" && s != "*" && s != "/") return stoi(s);
        
        int r2 = evalRPN(tokens), r1 = evalRPN(tokens);
        cout << r2 << " " << r1;
        if(s == "+") return r1 + r2;
        if(s == "-") return r1 - r2;
        if(s == "*") return r1 * r2;
        if(s == "/") return r1 / r2;
    }
};

