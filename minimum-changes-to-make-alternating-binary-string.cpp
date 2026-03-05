class Solution {
public:
    int minOperations(string s) {
        // it can have two patterns
        // 010101... (start0)
        // 101010... (start1)
        int start0 = 0;
        int start1 = 0;

        for(int i=0;i<s.length();i++){
            if(i%2==0){ // even like 0, 2, 4....
                if(s[i]=='0') start1++;
                else start0++;
            }
            else{ // odd
                if(s[i]=='1') start1++;
                else start0++;
            }
        }
        return min(start0, start1);
    }
};