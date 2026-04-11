class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int result = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            mp[num].push_back(i);

            auto &v = mp[num];

            
            if (v.size() > 3) {
                v.erase(v.begin());
            }

            
            if (v.size() == 3) {
                int dist = 2 * (v[2] - v[0]);
                result = min(result, dist);
            }
        }

        return (result == INT_MAX ? -1 : result);
    }
};