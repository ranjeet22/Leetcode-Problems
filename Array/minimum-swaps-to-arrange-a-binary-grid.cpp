class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> endZeros(n, 0); //count of consecutive 0s from the end of ith row
        for(int i = 0; i < n; i++) {
            int j = n-1;
            int count = 0;
            while(j >= 0 && grid[i][j] == 0) {
                count++;
                j--;
            }
            endZeros[i] = count;
        }

        int steps = 0;
        for(int i = 0; i < n; i++) {
            int need = n - i - 1;
            int j = i;
            while(j < n && endZeros[j] < need) j++;

            if(j == n) return -1;

            steps += j-i;
            while(j > i) {
                swap(endZeros[j], endZeros[j-1]);
                j--;
            }
        }
        return steps;
    }
};