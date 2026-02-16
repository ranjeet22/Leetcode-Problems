class Solution {
public:
    int reverseBits(int n) {
        if(n==0) return 0;
        
        int result = 0;
        for(int i=1;i<=32;i++){
            result<<=1; // left shift for space
            result = result | (n & 1);
            n>>=1; // right shift to move to next bit
        }
        return result;
    }
};