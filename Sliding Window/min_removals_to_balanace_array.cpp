class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        // sliding window problem
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0;
        int maxlen = 1;
        for(int r=0;r<n;r++){
            while((long long)nums[r] > k * (long long)nums[l]){
                l++;
            }
            maxlen = max(maxlen, r-l+1);
        }

        int count = n - maxlen;
        return count;
    }
};