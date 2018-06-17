class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(i < nums1.size() && j < nums2.size()){
            if(nums1[i] < nums2[j]) i++;
            else if(nums1[i] > nums2[j]) j++;
            else{
                if(res.empty() || res.back() != nums1[i]){
                    res.push_back(nums1[i]);
                }
                i++; j++;
            }
        }
        return res;
    }
};
