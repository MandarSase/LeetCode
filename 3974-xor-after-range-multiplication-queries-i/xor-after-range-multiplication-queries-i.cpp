class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;

        for (auto& q : queries) {
            int l = q[0];
            int r = q[1];
            int step = q[2];
            int val = q[3];

            for (int i = l; i <= r; i += step) {
                nums[i] = (1LL * nums[i] * val) % mod;
            }
        }

        int result = 0;
        for (int x : nums) {
            result ^= x;
        }

        return result;
    }
};