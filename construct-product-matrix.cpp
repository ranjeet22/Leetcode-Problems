class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int MOD = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> p(n, vector<int>(m)); //result = product matrix

        long long suffix = 1;
        for(int i = n-1; i >= 0; i--) {
            for(int j = m-1; j >= 0; j--) {
                p[i][j] = suffix;
                suffix = (suffix * grid[i][j]) % MOD;
            }
        }

        long long prefix = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                p[i][j] = (prefix * p[i][j]) % MOD;
                prefix = (prefix * grid[i][j]) % MOD;
            }
        }

        return p;

    }
};