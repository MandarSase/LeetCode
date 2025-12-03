class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> ans;

        int a = nums1.size();
        int b = nums2.size();

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (nums1[i] == nums2[j]) {
                    ans.insert(nums1[i]);
                    break;
                }
            }
        }

        vector<int> result(ans.begin(), ans.end());
        return result;
    }
};
