class Solution {
public:
    int square_sum(int n){
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum += digit * digit;
            n/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow=n, fast=n;
        while(fast!=1){
            slow = square_sum(slow);
            fast = square_sum(fast);
            fast = square_sum(fast);

            if(slow==fast && fast!=1) return false;
        }
        return true;
    }
};