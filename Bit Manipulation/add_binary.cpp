class Solution {
public:
    string addBinary(string a, string b) {
        // 0 + 0 = 0, carry = 0
        // 1 + 0 = 1, carry = 0
        // 1 + 1 = 0, carry = 1         2->10
        // 1 + 1 + 1 = 0, carry = 1     3->11
        // result = sum%2

        int m = a.length() - 1;
        int n = b.length() - 1;
        int sum=0, carry=0;
        string result = "";

        while(m>=0 || n>=0){
            sum = carry;
            if(m>=0) sum += (a[m--] - '0'); // gets the integer value
            if(n>=0) sum += (b[n--] - '0');

            result.push_back((sum%2==0)? '0' : '1');
            carry = (sum>1)? 1 : 0;
        }

        if(carry == 1) result.push_back('1');
        reverse(begin(result), end(result));
        return result;
    }
};