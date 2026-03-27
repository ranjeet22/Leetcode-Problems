class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // prev_row, curr_row
        vector<double> prev_row(1, poured);
        for(int row=1; row<=query_row; row++){
            vector<double> curr_row(row+1, 0.0);
            for(int i=0; i<row; i++){
                double extra = prev_row[i] - 1;
                if(prev_row[i]>1){
                    curr_row[i] += extra/2.0;
                    curr_row[i+1] += extra/2.0;
                }
            }
            prev_row = curr_row;
        }
        return min(1.0, prev_row[query_glass]);
    }
};