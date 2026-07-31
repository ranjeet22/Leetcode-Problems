class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st; // stores the unique codes
        int count = pow(2,k); // total unique codes possible
        int n = s.length();

        for(int i=k;i<=n;i++){
            string sub = s.substr(i-k, k);
            if(!st.count(sub)){
                st.insert(sub);
                count--;
            }
            if(count==0) return true;
        }
        return false;
    }
};