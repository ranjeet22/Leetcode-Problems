class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char, int> need, window;
        int left = 0;
        int right = 0;
        int start = left;
        int min_len = INT_MAX;

        for(int i=0;i<t.size();i++){ // stores each char of t with freq
            char c = t[i];
            need[c]++;
        }

        int required = need.size(); // number of unique chars in t
        int formed = 0; // how many chars currently satisfied

        while(right<s.size()){
            char c = s[right];
            window[c]++;
            if(need[c]>0 && window[c]==need[c]) formed++;

            while(formed==required){ // valid window
                int len = right-left+1;
                if(len<min_len){
                    start = left; // update the values
                    min_len = len;
                }

                // shrink
                char d = s[left];
                window[d]--;
                if(need[d]>0 && window[d]<need[d]) formed--;
                left++;
            }
            right++;
        }
        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};