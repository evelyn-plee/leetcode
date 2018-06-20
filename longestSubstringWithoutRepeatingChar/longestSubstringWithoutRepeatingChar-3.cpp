class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    size_t longest=0;
	size_t b=0;
	int l[256];
	memset(l, 0xFF, sizeof(l));

	for(size_t e=0; e<s.size();)
	{
		char c = s[e];
		auto p = l[s[e]];
		if(p>=b && p<e)
			b=p+1;
		l[s[e]] = max(l[s[e]], int(e));
		++e;
		longest = max(longest, e-b);
	}
	return longest;
    }
};
