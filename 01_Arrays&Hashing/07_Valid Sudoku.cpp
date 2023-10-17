class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> suqures;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    continue;
                }

                int area = (r/3) * 3 + (c/3);
                if (cols[c].find(board[r][c]) != cols[c].end() ||
                    rows[r].find(board[r][c]) != rows[r].end() || 
                    suqures[area].find(board[r][c]) != suqures[area].end()) 
                {
                    return false;
                }
                
                cols[c].insert(board[r][c]);
                rows[r].insert(board[r][c]);
                suqures[area].insert(board[r][c]);
            }
        }

        return true;
    }
};