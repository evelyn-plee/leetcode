class Solution{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> map;
    vector<int> result;
    for(auto a:nums1) ++map[a];
    for(auto b:nums2){
      if (map[a]-->0) result.push_back(a);
    }
    return result;
  }
}
