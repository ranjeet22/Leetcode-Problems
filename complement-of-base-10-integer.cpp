class Solution {
public:
    int bitwiseComplement(int n) {
        // XOR of 101 with 111 is 010
        int k = 1;
        while(k<n){
            k = k<<1;
            k = k|1;
        }
        return k^n;
    }
};