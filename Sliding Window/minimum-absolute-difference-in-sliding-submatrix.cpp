class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> result(m-k+1, vector<int>(n-k+1, 0));
        
        for (int i = 0; i <= m-k; i++) {
            for (int j = 0; j <= n-k; j++) {
                
                // Set for distinct + sorted
                set<int> vals;
                
                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.insert(grid[r][c]);
                    }
                }
                
                // If all elements were same, set has only 1 element
                if (vals.size() == 1) {
                    continue;
                }
                
                int minAbsDiff = INT_MAX;
                auto prev = vals.begin();
                auto curr = next(prev);
                
                while (curr != vals.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                
                result[i][j] = minAbsDiff;
            }
        }
        
        return result;
    }
};