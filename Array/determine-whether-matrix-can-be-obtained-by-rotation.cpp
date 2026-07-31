class Solution {
public:
    // Rotate clockwise : Transpose + Reverse row wise
    // Rotate anti-clockwise : Transpose + Reverse column wise

    int n;
    void rotate(vector<vector<int>>& mat) {
        //Transpose
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        //Reverse row wise
        for(int i = 0; i < n; i++) {
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        for(int c = 1; c <= 4; c++) {
            bool equal = true;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(mat[i][j] != target[i][j]) {
                        equal = false;
                        break;
                    }
                }
                if(!equal) break;
            }
            if(equal) return true;
                
            rotate(mat);
        }
        return false;
    }
};