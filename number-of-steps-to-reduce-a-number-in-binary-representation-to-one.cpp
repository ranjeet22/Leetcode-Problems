class Solution {
public:
    int numSteps(string s) {
        int n = s.length();

        int op = 0;
        int carry = 0;

        for(int i = n-1; i >= 1; i--) {
            if(((s[i] - '0') + carry) % 2 == 1) { //odd
                op += 2;
                carry = 1;
            } else {
                op += 1;
            }
        }

        return op + carry;
    }
};