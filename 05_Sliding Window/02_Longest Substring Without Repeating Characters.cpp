class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxSize = 0;
        int l = 0;
        int r = 0;
        unordered_set<char> c;

        while (r < s.size()) {
            while (c.find(s[r]) != c.end()) {
                c.erase(s[l]);
                l++;
            }

            maxSize = max(maxSize, r - l + 1);
            c.insert(s[r]);
            r++;
        }

        return maxSize;    
    }
};