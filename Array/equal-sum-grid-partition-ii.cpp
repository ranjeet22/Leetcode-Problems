class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (check(grid)) return true;
        
        // Transpose grid to check vertical cuts using the same horizontal logic
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                transposed[j][i] = grid[i][j];
            }
        }
        return check(transposed);
    }

private:
    bool check(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long totalSum = 0;
        vector<long long> rowSum(m, 0);
        map<int, int> bottomFreq;
        map<int, int> topFreq;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowSum[i] += grid[i][j];
                totalSum += grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }
        
        long long topSum = 0;
        for (int i = 0; i < m - 1; ++i) {
            topSum += rowSum[i];
            for (int j = 0; j < n; ++j) {
                topFreq[grid[i][j]]++;
                bottomFreq[grid[i][j]]--;
                if (bottomFreq[grid[i][j]] == 0) {
                    bottomFreq.erase(grid[i][j]);
                }
            }
            
            long long bottomSum = totalSum - topSum;
            if (topSum == bottomSum) return true;
            
            if (topSum > bottomSum) {
                long long diff = topSum - bottomSum;
                if (canRemove(diff, topFreq, 0, i, 0, n - 1, grid)) {
                    return true;
                }
            } else {
                long long diff = bottomSum - topSum;
                if (canRemove(diff, bottomFreq, i + 1, m - 1, 0, n - 1, grid)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool canRemove(long long val, const map<int, int>& freq, int r1, int r2, int c1, int c2, const vector<vector<int>>& grid) {
        if (freq.find(val) == freq.end()) return false;
        
        int height = r2 - r1 + 1;
        int width = c2 - c1 + 1;
        
        // If the section spans >1 row and >1 column, any cell removal keeps it connected.
        if (height > 1 && width > 1) return true;
        
        // If it's a single row (height == 1, width > 1)
        if (height == 1 && width > 1) {
            // Can only remove if 'val' is at the leftmost or rightmost endpoint of this segment
            return (grid[r1][c1] == val || grid[r1][c2] == val);
        }
        
        // If it's a single column (height > 1, width == 1)
        if (height > 1 && width == 1) {
            // Can only remove if 'val' is at the topmost or bottommost endpoint of this segment
            return (grid[r1][c1] == val || grid[r2][c1] == val);
        }
        
        // If it's a 1x1 section, removing the cell makes it empty, which violates the non-empty section rule.
        return false;
    }
};