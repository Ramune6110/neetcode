class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix[0].size()- 1;
        int m = matrix.size();

        for (int i = 0; i < m; i++) {
            if (matrix[i][l] <= target || target <= matrix[i][r]) {
                vector<int> tempvec = matrix[i];
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (tempvec[mid] == target) {
                        return true;
                    } else if (tempvec[mid] < target) {
                        l++;
                    } else if (tempvec[mid] > target) {
                        r--;
                    }
                }

                l = 0;
                r = matrix[0].size()- 1;
            }
        }

        return false;
    }
};

/*
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool res = false;

        for (int i = 0; i < m; i++) {
            vector<int> tmpvec = matrix[i];
            if (tmpvec[0] <= target && target <= tmpvec[n - 1]) {
                int l = 0;
                int r = n - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (tmpvec[mid] == target) {
                        return true;
                    } else if (tmpvec[mid] < target) {
                        l++;
                    } else if (tmpvec[mid] > target) {
                        r--;
                    }
                }
            }
        }

        return res;
    }
};
*/