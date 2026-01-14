#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int nums[] = {1,1,1,2,2,3};
    int n = sizeof(nums) / sizeof(nums[0]); //n = arr.size() in case of vector

    int low = 0;
    int high = 1;
    int unique_count = 1;

    while(high<n){
        if(nums[high]!=nums[low]){
            low++;
            nums[low] = nums[high];
            unique_count++;
        }
        high++;
    }
    cout<<unique_count;
}