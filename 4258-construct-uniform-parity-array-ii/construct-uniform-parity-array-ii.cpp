class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int mn = INT_MAX;
        for (int x : a)
            if (x & 1) mn = min(mn, x);

        if (mn == INT_MAX) return true;

        for (int x : a)
            if (x != mn && x < mn) return false;

        return true;
    }
};