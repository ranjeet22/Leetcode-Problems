class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        long long tri_count = 0;

        sort(arr, arr + n);

        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                long long tri_sum = arr[left] + arr[right] + arr[i];
                if(tri_sum<sum){
                    tri_count += right-left;
                    left++;
                }
                else right--;
            }
        }
        return tri_count;
    }
};