class Solution {
public:
    int m;
    int n;
    int t[501][501][3];

    int solve(vector<vector<int>>& coins, int i, int j, int neu) {
        if(i == m-1 && j == n-1) {
            if(coins[i][j] < 0 && neu > 0) return 0;
            return coins[i][j];
        }

        if(i >= m || j >= n) return INT_MIN;

        if(t[i][j][neu] != INT_MIN) return t[i][j][neu];

        //Take the current cell value
        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        //Skip current value if you can
        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return t[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {

        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < 501; i++) {
            for(int j = 0; j < 501; j++) {
                for(int k = 0; k < 3; k++) {
                    t[i][j][k] = INT_MIN;
                }
            }
        }

        return solve(coins, 0, 0, 2);
    }
};