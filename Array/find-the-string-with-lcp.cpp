class Solution {
public:
    bool checkLCP(string &word, vector<vector<int>>& lcp) {
        int n = word.length();

        for(int i = 0; i < n; i++) {
            //lcp[i][n-1] = (word[i] == word[n-1]) ? 1 : 0;
            if(word[i] != word[n-1]) {
                if(lcp[i][n-1] != 0) return false;
            } else {
                if(lcp[i][n-1] != 1) return false;
            }
        }

        for(int j = 0; j < n; j++) {
            //lcp[n-1][j] = (word[n-1] == word[j]) ? 1 : 0;
            if(word[n-1] != word[j]) {
                if(lcp[n-1][j] != 0) return false;
            } else {
                if(lcp[n-1][j] != 1) return false;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            for(int j = n-2; j >= 0; j--) {
                if(word[i] == word[j]) {
                    if(lcp[i][j] != 1 + lcp[i+1][j+1]) return false;
                } else {
                    if(lcp[i][j] != 0) return false;
                }
            }
        }

        return true;
    }

    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();

        string word(n, '$');

        for(int i = 0; i < n; i++) {

            //word[i] = ?
            for(int j = 0; j < i; j++) {
                if(lcp[j][i] != 0) {
                    word[i] = word[j];
                    break;
                }
            }


            if(word[i] == '$') {
                vector<bool> forbidden(26, false);

                for(int j = 0; j < i; j++) {
                    if(lcp[j][i] == 0) {
                        forbidden[word[j] - 'a'] = true;
                    }
                }

                //a, b, c ..., z
                for(int idx = 0; idx < 26; idx++) {
                    if(forbidden[idx] == false) {
                        word[i] = idx + 'a';
                        break;
                    }
                }

                if(word[i] == '$')
                    return ""; //we could never fill word[i]
            }
        }

        return checkLCP(word, lcp) == true ? word : "";
    }
};