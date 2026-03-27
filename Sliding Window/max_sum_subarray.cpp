class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low = 0;
        int high = k-1;
        int max_sum = 0;
        
        int sum = 0;
        for(int i=low;i<=high;i++){
            sum+=arr[i];
        }
        if(max_sum<sum) max_sum = sum;
        
        while(high<arr.size()-1){
            sum = sum - arr[low++] + arr[++high];
            if(max_sum<sum) max_sum = sum;
        }
        return max_sum;
    }
};