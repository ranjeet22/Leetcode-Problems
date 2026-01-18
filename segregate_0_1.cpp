// User function template for C++

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        // code here
        int zero=0;
        int one =0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0) zero++;
            else one++;
        }
        
        arr.clear();
        
        while(zero>0){
            arr.push_back(0);

            arr.push_back(1);


            zero--;
        }
        while(one>0){
            arr.push_back(1);
            one--;
        }
    }
};


