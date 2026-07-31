class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Compute 2D Prefix Sum in-place
                if (i > 0) grid[i][j] += grid[i - 1][j];
                if (j > 0) grid[i][j] += grid[i][j - 1];
                if (i > 0 && j > 0) grid[i][j] -= grid[i - 1][j - 1];

                // Check condition
                if (grid[i][j] <= k) {
                    count++;
                } else {
                    // Early exit for current row since elements are non-negative
                    break;
                }
            }
        }

        return count;
    }
};