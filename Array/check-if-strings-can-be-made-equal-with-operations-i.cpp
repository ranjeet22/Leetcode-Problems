class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int even[26] = {0};
        int odd[26] = {0};

        int n = s1.length();

        for(int i = 0; i < 4; i++) {
            if(i%2 == 0) { //even indices
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else { //odd indices
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(even[i] != 0 || odd[i] != 0)
                return false;
        }

        return true;
    }
};