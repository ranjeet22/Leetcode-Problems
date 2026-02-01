class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int noDel = arr[0];
        int oneDel = INT_MIN;
        int max_sum = arr[0];
        int temp;

        for(int i=1;i<arr.size();i++){
            (oneDel == INT_MIN)? temp = arr[i] : temp = oneDel+arr[i]; // with 1 deletion - 2 cases
            oneDel = max(temp, noDel); // already deleted or deletion of arr[i]

            noDel = max(arr[i], arr[i]+noDel); // without deletion - simple Kadane
            max_sum = max(max_sum, max(noDel, oneDel));
        }
        return max_sum;
    }
};