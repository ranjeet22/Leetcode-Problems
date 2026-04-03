class Solution {
public:
    int rob(vector<int>& nums) {
        // At each house you have 2 options
        //     skip: dp[i] = dp[i-1];
        //     rob: dp[i] = dp[i-2] + nums[i];

        int prev2 = 0; //dp[i-2]
        int prev1 = 0; //dp[i-1]

        for(int num : nums){
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};