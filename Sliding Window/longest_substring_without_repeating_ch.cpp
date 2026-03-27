class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int max_len = 0;
        unordered_map<char, int> f;

        for(int high=0;high<s.size();high++){
            f[s[high]]++;
            int k = high-low+1; // window size

            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0) f.erase(s[low]);
                low++;
                k = high-low+1; // k value depends on low
            }

            if(f.size()==k){
                int len = high-low+1;
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};