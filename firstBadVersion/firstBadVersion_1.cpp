// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    void search(int start, int end, int &res){
        if (start > end){ return; }
        else{
            int mid = start + (end - start)/2;
            int tmp = isBadVersion(mid);
            if(tmp){
                res = mid;
                search(start, mid-1, res);
            } else {
                search(mid+1, end, res);
            }
        }
    }

    int firstBadVersion(int n){
        int res = n;
        search(1, n, res);
        return res;
    }
};
