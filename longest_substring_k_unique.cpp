class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int low = 0;
        int max_len = -1;
        unordered_map<char, int> f;
        
        for(int high=0;high<s.size();high++){
            f[s[high]]++; // add and increasing frequency
            
            while(f.size()>k){
                f[s[low]]--; // decreasing frequency
                if(f[s[low]]==0) f.erase(s[low]);
                low++;
            }
            
            if(f.size()==k){
                int len = high-low+1;
                max_len = max(max_len, len);
            }
            
        }
        return max_len;
    }
};