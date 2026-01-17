class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int min_diff  = INT_MAX;
        int res_sum = 0;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                int sum = nums[left] + nums[right] + nums[i];
                int diff = abs(target - sum);
                if(diff<min_diff){
                    min_diff = diff;
                    res_sum = sum;
                }

                if (sum < target) left++;
                else if (sum > target) right--;
                else return sum;
            }
        }
        return res_sum;
    }
};