class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        int i = 0;
        
        while(i<n){
            int j = i+1; // using j so we can use i as start of subarray
            while(j<n && nums[j]>nums[j-1]) j++;
            int p = j-1;
            if(p==i) {i++; continue;} // no increasing segment or steady phase

            j = p+1;
            while(j<n && nums[j]<nums[j-1]) j++;
            int q = j-1;
            if(q==p) {i=p; continue;}

            j = q+1;
            while(j<n && nums[j]>nums[j-1]) j++;
            int r = j-1;
            if(r==q) {i=q; continue;}
            // now we have the subarray:
            // i -> p -> q -> r

            long long coresum = 0; // sum of p -> q
            for(int k=p; k<=q; k++) coresum += nums[k];

            long long maxleft = LLONG_MIN, curr = 0; // sum of i -> p-1
            for(int k=p-1; k>=i; k--){
                curr += nums[k];
                maxleft = max(maxleft, curr);
            }

            long long maxright = LLONG_MIN; // sum of q+1 -> r
            curr = 0;
            for(int k=q+1; k<=r; k++){
                curr += nums[k];
                maxright = max(maxright, curr);
            }

            ans = max(ans, maxleft + coresum + maxright);
            i=q;
        }
        return (ans==LLONG_MIN)? -1: ans;
    }
};