class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        unordered_set<int> s(a.begin(),a.end());
        for(int i=1;;i++) if(!s.count(i*k)) return i*k;
    }
};