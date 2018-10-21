class Solution{
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto t : tokens){
            if(isdigit(t[0]) || t.length() > 1) nums.push(stoi(t));
            else{
                int x2 = nums.top(); nums.pop();
                int x1 = nums.top(); nums.pop();
                switch(t[0]){
                    case '+': 
                        x1 += x2;
                        break;
                    case '-': 
                        x1 -= x2;
                        break;
                    case '*': 
                        x1 *= x2;
                        break;
                    case '/': 
                        x1 /= x2;
                        break;
                }
                nums.push(x1);
            }
        }
        return nums.top();
    }
};

