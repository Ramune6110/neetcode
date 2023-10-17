class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }

        return result;
    }

    string getKey(string s) {
        vector<int> count(26);

        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        string key = "";
        for (int j = 0; j < count.size(); j++) {
            key.append(to_string(count[j] + '#'));
        }

        return key;
    }
};