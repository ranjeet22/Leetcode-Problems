class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n<4) return false;

        int i = 0;
        while(i+1<n && nums[i]<nums[i+1]) i++;
        int p = i;
        
        while(i+1<n && nums[i]>nums[i+1]) i++;
        int q = i;

        while(i+1<n && nums[i]<nums[i+1]) i++;
        int flag = i;

        return (p!=0) && (q!=p) && (flag==n-1 && flag!=q);
    }
};