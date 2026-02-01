class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currmax_sum = nums[0]; // kadane
        int max_sum = nums[0];

        int currmin_sum = nums[0]; // kadane in reverse
        int min_sum = nums[0]; 

        int absmax_sum = 0; // max of max_sum and abs(min_sum)

        for(int i=1;i<nums.size();i++){
            currmax_sum = max(nums[i], currmax_sum+nums[i]);
            max_sum = max(max_sum, currmax_sum);

            currmin_sum = min(nums[i], currmin_sum+nums[i]);
            min_sum = min(min_sum, currmin_sum);
        }
        absmax_sum = max(max_sum, abs(min_sum));
        return absmax_sum;
    }
};