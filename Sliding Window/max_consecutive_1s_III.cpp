class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int zero = 0;
        int max_len = 0;

        for(int high=0;high<nums.size();high++){
            if(nums[high]==0) zero++;

            while(zero>k){
                if(nums[low]==0) zero--;
                low++;
            }

            int len = high-low+1;
            max_len = max(max_len, len);
        }
        return max_len;
    }
};