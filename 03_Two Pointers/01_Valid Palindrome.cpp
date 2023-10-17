class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            while (l < r && !alphanum(s[l])) {
                l++;
            }
            while (r > l && !alphanum(s[r])) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
private:
    bool alphanum(char c) {
        return (('A' <= c && c <= 'Z') ||
                ('a' <= c && c <= 'z') ||
                ('0' <= c && c <= '9'));
    }
};