class Solution {
public:
    int minPartitions(string n) {
        // Trick: Total steps is always equal to the highest element present in the string
        char maxchar = *max_element(begin(n), end(n));
        return maxchar - '0';
    }
};