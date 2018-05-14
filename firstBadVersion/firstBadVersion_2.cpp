bool isBadVersion(int version);

class Solution{
public:
    int firstBadVersion(int n){
        int low = 1;
        int high = n;
        int middle;
        while(low != high){
            middle = low + (high - low)/2;
            if(isBadVersion(middle)) high = middle;
            else low = middle + 1;
        }
        if(isBadVersion(low)) return low;
        else return -1;
    }
};
