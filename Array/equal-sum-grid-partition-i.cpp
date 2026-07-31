class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long total_sum = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                total_sum += grid[i][j];
            }
        }

        if(total_sum % 2 != 0) return false;

        // horizontal split
        long long sum = 0;
        for(int i=0; i<m-1; i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
            }
            if(sum == total_sum / 2) return true;
        }

        // virtical split
        sum = 0;
        for(int j=0; j<n-1; j++){
            for(int i=0;i<m;i++){
                sum += grid[i][j];
            }
            if(sum == total_sum / 2) return true;
        }

        return false;
    }
};