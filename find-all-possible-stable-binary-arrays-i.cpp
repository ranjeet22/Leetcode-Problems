class Solution {
public:
    int M = 1e9 + 7;
    int t[201][201][2];

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(t, 0, sizeof(t));
        t[0][0][0] = 1;
        t[0][0][1] = 1;

        for(int onesLeft = 0; onesLeft <= one; onesLeft++) {
            for(int zerosLeft = 0; zerosLeft <= zero; zerosLeft++) {
                if(onesLeft == 0 && zerosLeft == 0) continue;

                int result = 0;
                // if(lastWasOne == true) { explore 0s }
                result = 0;
                for(int len = 1; len <= min(zerosLeft, limit); len++) {
                    result = (result + t[onesLeft][zerosLeft - len][0]) % M;
                }
                t[onesLeft][zerosLeft][1] = result;

                // else { explore 1s }
                result = 0;
                for(int len = 1; len <= min(onesLeft, limit); len++) {
                    result = (result + t[onesLeft - len][zerosLeft][1]) % M;
                }
                t[onesLeft][zerosLeft][0] = result;
            }
        }
        int startWithOne  = t[one][zero][false];
        int startWithZero = t[one][zero][true];
        return (startWithOne + startWithZero) % M;
    }
};