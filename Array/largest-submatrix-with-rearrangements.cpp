class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int,int>> prevHeights;
        int result = 0;

        for (int row = 0; row < m; row++) {
            vector<pair<int,int>> heights;
            vector<bool> seen = vector<bool>(n, false);
            
            for (auto [height, col] : prevHeights) {
                if (matrix[row][col] == 1) {
                    heights.push_back({height + 1, col});
                    seen[col] = true;
                }
            }
            for (int col = 0; col < n; col++) {
                if (seen[col] == false && matrix[row][col] == 1) {
                    heights.push_back({1, col});
                }
            }
            for (int i = 0; i < heights.size(); i++) {
                int base   = (i+1);
                int height = heights[i].first;
                result = max(result, base*height);
            }
            prevHeights = heights;
        }
        return result;
    }
};