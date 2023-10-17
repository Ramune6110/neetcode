class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> suqures;

        for (int c = 0; c < 9; c++) {
            for (int r = 0; r < 9; r++) {
                if (board[c][r] == '.') {
                    continue;
                }

                int area = (r/3) * 3 + (c/3);
                if (cols[c].find(board[c][r]) != cols[c].end() ||
                    rows[r].find(board[c][r]) != rows[r].end() || 
                    suqures[area].find(board[c][r]) != suqures[area].end()) 
                {
                    return false;
                }
                
                cols[c].insert(board[c][r]);
                rows[r].insert(board[c][r]);
                suqures[area].insert(board[c][r]);
            }
        }

        return true;
    }
};