class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string str = s + s;
        string str0 = ""; // 01010101...
        string str1 = ""; // 10101010...

        for(int i=0;i<2*n;i++){
            str0 += (i%2==0)? '0' : '1';
            str1 += (i%2==0)? '1' : '0';
        }

        int diff0 = 0;
        int diff1 = 0;
        int result = INT_MAX;;
        int l=0, r=0;
        while(r<2*n){
            if(str[r]!=str0[r]) diff0++;
            if(str[r]!=str1[r]) diff1++;

            if(r-l+1 > n){
                if(str[l]!=str0[l]) diff0--;
                if(str[l]!=str1[l]) diff1--;
                l++;
            }

            if(r - l + 1 == n) result = min(result, min(diff0, diff1));
            r++;
        }
        return result;
    }
};