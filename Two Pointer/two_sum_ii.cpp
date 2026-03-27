#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[] = {2,1,3,5,7};
    int target = 6;
    int n = sizeof(arr) / sizeof(arr[0]); //n = arr.size() in case of vector
    sort(arr,arr+n);
    
    int i=0, j = n-1;
    while(i<j){
        if(arr[i]+arr[j] == target){
            cout<<arr[i]<<" "<<arr[j];
            break;
        }
        else if(arr[i]+arr[j] > target) j--;
        else i++;
    }
}