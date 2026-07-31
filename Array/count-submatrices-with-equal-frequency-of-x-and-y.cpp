class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Prefix sum array for values ('X' -> 1, 'Y' -> -1, '.' -> 0)
        vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
        // Prefix count array for 'X'
        vector<vector<int>> has_x(n + 1, vector<int>(m + 1, 0));
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int val = 0;
                int x_count = 0;
                if (grid[i][j] == 'X') {
                    val = 1;
                    x_count = 1;
                } else if (grid[i][j] == 'Y') {
                    val = -1;
                }
                
                // Compute 2D prefix sums
                sum[i + 1][j + 1] = val + sum[i][j + 1] + sum[i + 1][j] - sum[i][j];
                has_x[i + 1][j + 1] = x_count + has_x[i][j + 1] + has_x[i + 1][j] - has_x[i][j];
                
                // Check conditions: equal frequency (sum == 0) and at least one 'X'
                if (sum[i + 1][j + 1] == 0 && has_x[i + 1][j + 1] > 0) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};