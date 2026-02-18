class Solution {
public:
    bool hasAlternatingBits(int n) {
        // keep comparing last bit with the 2nd last bit
        int prev = n & 1;
        n>>=1;
        while(n>0){
            int curr = n & 1;
            if(curr == prev) return false;
            prev = curr;
            n>>=1;
        }
        return true;
    }
};