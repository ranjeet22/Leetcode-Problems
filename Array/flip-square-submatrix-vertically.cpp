class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int start_row = x;
        int end_row = x + k - 1;

        int start_col = y;
        int end_col = y + k - 1;

        for(int i = start_row; i <= end_row; i++){
            for(int j = start_col; j <= end_col; j++){
                swap(grid[i][j], grid[end_row][j]);
            }
            end_row--;
        }
        return grid;
    }
};