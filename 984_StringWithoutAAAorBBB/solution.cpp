class Solution{
public:
    string strWithout3a3b(int A, int B){
    
        char a = 'a';
        char b = 'b';
        
        if(B > A){
            swap(A, B);
            swap(a, b);
        }
    
        string res = "";
        while(A || B){
            if(A > 0){ res += a; A--; }
            if(A > B){ res += a; A--; }
            if(B > 0){ res += b; B--; }
        }
        return res;
    }
}
