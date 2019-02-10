 class Solution(object):
    def strWithout3a3b(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: str
        """
        
        a = 'a'
        b = 'b'
        
        if(B > A):
            B, A = A, B
            b, a = a, b
            
        res = ""
        while A or B:
            if(A > 0):
                res += (a)
                A -= 1
            if(A > B):
                res += (a)
                A -= 1
            if(B > 0):
                res += (b)
                B -= 1
                
        return res
                
