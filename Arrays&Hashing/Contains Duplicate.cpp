class Solution {
public:
    /* HashSet */
    bool containsDuplicate(vector<int>& nums) {
      unordered_set<int> s;

      for (int i = 0; i < nums.size(); i++) {
        if (s.find(nums[i]) != s.end()) {
          return true;
        }
        s.insert(nums[i]);
      }

      return false;
    }
    

    /* Sort */
    /*
    bool containsDuplicate(vector<int>& nums) {
      sort(nums.begin(), nums.end());

      if (nums.size() > 2) {
        for (int i = 1; i < nums.size(); i++) {
          if (nums[i - 1] == nums[i]) {
            return true;
          }
        }
      } else if (nums.size() == 2) {
          if (nums[0] == nums[1]) {
            return true;
          }
      } else if (nums.size() == 1) {
        return false;
      }

      return false;
    }
    */

    /* simple but Time Limit Exceeded */
    /*bool containsDuplicate(vector<int>& nums) {
      for (int i = 0; i < nums.size(); i++) {
        int tmp = nums[i];
        for (int j = i + 1; j < nums.size(); j++) {
          if (tmp == nums[j]) {
            return true;
          }
        }
      }
      return false;
    }
    */
};