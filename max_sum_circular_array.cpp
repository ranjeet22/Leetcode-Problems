class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = nums[0];
        int curr_max = nums[0], max_sum = nums[0];
        int curr_min = nums[0], min_sum = nums[0];

        for(int i=1;i<nums.size();i++){
            curr_max = max(nums[i], nums[i]+curr_max);
            max_sum = max(max_sum, curr_max);

            curr_min = min(nums[i], nums[i]+curr_min);
            min_sum = min(min_sum, curr_min);

            total+=nums[i];
        }

        if(max_sum<0) return max_sum; // all negative elements
        return max(max_sum, total-min_sum);
    }
};