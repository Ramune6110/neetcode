class Solution {
public:
    /* Hashmap */
    /*
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for (int i = 0; i < s.size(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }

        for (int i = 0; i < countS.size(); i++) {
            std::cout << countS[i] << std::endl;
            std::cout << countT[i] << std::endl;
            if (countS[i] != countT[i]) {
                return false;
            }
        }

        return true;   
    }
    */
    
    /* sort */
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s != t) {
            return false;
        } else {
            return true;   
        }
    }
};