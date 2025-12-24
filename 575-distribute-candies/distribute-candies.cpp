class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        unordered_set<int> types(candyType.begin(), candyType.end());
        return min((int)types.size(), (int)candyType.size() / 2);
        
    }
};