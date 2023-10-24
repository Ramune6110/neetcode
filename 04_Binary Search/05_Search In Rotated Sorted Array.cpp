class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && nums[mid] >= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[r] >= target && nums[mid] <= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return res;
    }
};