class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int cols = n / rows;

        string ans;

        for (int col = 0; col < cols; ++col) {
            int i = 0, j = col;
            while (i < rows && j < cols) {
                ans.push_back(encodedText[i * cols + j]);
                i++;
                j++;
            }
        }

        while (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }

        return ans;
    }
};