class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int max_len = -1;
        unordered_map<int, int> f;
        int k =2; // distinct element

        for(int high=0;high<fruits.size();high++){
            f[fruits[high]]++;

            while(f.size()>k){
                f[fruits[low]]--;
                if(f[fruits[low]]==0) f.erase(fruits[low]);
                low++;
            }
            if(f.size()<=k){
                int len = high-low+1;
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};