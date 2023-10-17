class Solution {
public:
    /* O(n^2) Time Limit Exceeded */
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 0);

        for (int i = 0; i < nums.size(); i++) {
            int tmp_num = nums[i];
            int i_index = i;
            vector<int> tmp_vec = nums;
            for (int j = i + 1; j < tmp_vec.size(); j++) {
                std::cout << tmp_num << std::endl;
                std::cout << tmp_vec[j] << std::endl;
                if (tmp_num + tmp_vec[j] == target) {
                    int j_index = j;
                    if (i_index < j_index) {
                        ans[0] = i_index;
                        ans[1] = j_index;
                        return ans;
                    } else {
                        ans[0] = j_index;
                        ans[1] = i_index;
                        return ans;
                    }
                }
            }
        }

        return ans;
    }
    */

    /* Hashmap */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int tmp = target- nums[i];
            if (mp.find(tmp) != mp.end()) {
                return {mp[tmp], i};
            }

            mp.insert({nums[i], i});
        }

        return {};
    }
};