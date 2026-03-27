class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // slow & fast pointer approach
        int slow=0, fast=0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow!=fast); // cycle detected

        int entry = 0;
        while(slow!=entry){
            entry = nums[entry];
            slow = nums[slow];
        }
        return entry; // entry point of the cycle
    }
};