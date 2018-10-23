// O(n), O(n)

class Solution{
public:
     int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers.size());
        for(int i=0; i<flowers.size();i++)days[flowers[i] - 1] = i + 1;
        int left = 0, right = k + 1, res = INT_MAX;
        for(int i = 0; right < days.size(); i++){
            if(days[i] < days[left] || days[i] <= days[right]){   
                if(i == right)res = min(res, max(days[left], days[right]));    //we get a valid subarray
                left = i, right = k + 1 + i;
            }
        }
        return (res == INT_MAX)?-1:res;
    }
};
