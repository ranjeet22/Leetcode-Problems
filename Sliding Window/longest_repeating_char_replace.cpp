class Solution {
public:
    int findMaxFreq(vector<int> &f) {
    int maxCount = 0;
    for(int i = 0; i < 256; i++) {
        maxCount = max(maxCount, f[i]);
    }
    return maxCount;
    }

    int characterReplacement(string s, int k) {
    int low = 0;
    int max_len = 0;
    vector<int> f(256, 0);

    for(int high=0;high<s.size();high++){
        f[s[high]]++;
        int len = high-low+1;
        int max_cnt = findMaxFreq(f);
        int diff = len - max_cnt;

        while(diff>k){ // shrink
            f[s[low]]--;
            low++;
            len = high-low+1;
            max_cnt = findMaxFreq(f);
            diff = len - max_cnt;
        }

        if(diff<=k){
            len = high-low+1;
            max_len = max(max_len, len);
        }
    }
    return max_len;
    }
};