// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int current_sum = a[0];
        int min_sum = a[0];
        for(int i=1;i<a.size();i++){
            current_sum = min(a[i], current_sum+a[i]);
            min_sum = min(min_sum, current_sum);
        }
        return min_sum;
    }
};
