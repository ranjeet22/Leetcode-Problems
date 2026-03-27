class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        
        for(int i=0;i<n;i++){
            unordered_set <int> even, odd;
            for(int j=i;j<n;j++){
                (nums[j]%2==0) ? even.insert(nums[j]) : odd.insert(nums[j]);
                if(even.size() == odd.size()){
                    int len = j-i+1;
                    maxlen = max(maxlen, len);
                }
            }
        }
        return maxlen;
    }
};