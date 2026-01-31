class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = nums[0];
        int min_product = nums[0];
        int result = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0) swap(max_product, min_product);

            max_product = max(nums[i], nums[i]*max_product);
            min_product = min(nums[i], nums[i]*min_product);
            result = max(result, max_product);
        }
        return result;
    }
};