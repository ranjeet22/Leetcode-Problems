class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int cols = size(encodedText) / rows;
        string result;
        for (int i = 0; i < cols; ++i) {
            for (int j = i; j < size(encodedText); j += cols + 1) {
                result.push_back(encodedText[j]);
            }
        }
        while (!empty(result) && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};