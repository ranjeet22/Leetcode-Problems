class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int sum = 0;
        int min_len = INT_MAX;

        for(int high=0;high<nums.size();high++){
            sum+=nums[high];

            while(sum>=target){
                int len = high-low+1;
                min_len = min(min_len, len);
                sum-=nums[low];
                low++;
            }
        }
        return min_len==INT_MAX? 0:min_len; 
        // if(min_len == INT_MAX) retun 0;
        // else return min_len;
    }
};