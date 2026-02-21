class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int> primes = {2,3,5,7,11,13,17,19};
        int count = 0;

        for(int i=left;i<=right;i++){
            int setbits = __builtin_popcount(i); // used to count set bits
            if(primes.count(setbits)) count++;
        }
        return count;
    }
};