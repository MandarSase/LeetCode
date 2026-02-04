class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        long long ans = LLONG_MIN;

        while (i < n) {
            int l = i;
            i++;

            // strictly increasing
            while (i < n && nums[i - 1] < nums[i]) {
                i++;
            }
            if (i == l + 1) continue;

            int p = i - 1;
            long long s = (long long)nums[p - 1] + nums[p];

            // strictly decreasing
            while (i < n && nums[i - 1] > nums[i]) {
                s += nums[i];
                i++;
            }
            if (i == p + 1 || i == n || nums[i - 1] == nums[i]) continue;

            int q = i - 1;

            // start second increasing
            s += nums[i];
            i++;

            long long mx = 0, t = 0;
            while (i < n && nums[i - 1] < nums[i]) {
                t += nums[i];
                mx = max(mx, t);
                i++;
            }
            s += mx;

            // extend first increasing backwards
            mx = 0;
            t = 0;
            for (int j = p - 2; j >= l; j--) {
                t += nums[j];
                mx = max(mx, t);
            }
            s += mx;

            ans = max(ans, s);
            i = q;
        }
        return ans;
    }
};
