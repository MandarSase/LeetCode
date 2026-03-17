class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& mat) {
        int cols = mat[0].size();
        vector<int> height(cols, 0);
        int ans = 0;

        for (auto& row : mat) {
            
            for (int i = 0; i < cols; ++i)
                height[i] = row[i] ? height[i] + 1 : 0;

            
            auto sorted = height;
            sort(sorted.begin(), sorted.end());

            
            for (int i = 0; i < cols; ++i)
                ans = max(ans, sorted[i] * (cols - i));
        }

        return ans;
    }
};