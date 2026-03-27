class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> neg, pos;

        for (int x : nums) {
            if (x < 0) neg.push_back(x);
            else pos.push_back(x);
        }

        if (neg.empty()) { // All positive
            for (int &x : pos) x = x * x;
            return pos;
        }

        if (pos.empty()) { // All negative
            for (int &x : neg) x = x * x;
            reverse(neg.begin(), neg.end());
            return neg;
        }

        // Square negatives and reverse
        for (int &x : neg) x = x * x;
        reverse(neg.begin(), neg.end());

        // Square positives
        for (int &x : pos) x = x * x;

        // Merge
        int i = 0, j = 0;
        vector<int> res;

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] < pos[j]) res.push_back(neg[i++]);
            else res.push_back(pos[j++]);
        }

        while (i < neg.size()) res.push_back(neg[i++]);
        while (j < pos.size()) res.push_back(pos[j++]);

        return res;
    }
};
