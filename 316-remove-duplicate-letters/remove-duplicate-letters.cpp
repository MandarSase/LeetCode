class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> used(26, false);
        string result;

        for(char c : s)
            freq[c - 'a']++;

        for(char c : s) {
            freq[c - 'a']--;

            if(used[c - 'a']) continue;

            while(!result.empty() && 
                  result.back() > c &&
                  freq[result.back() - 'a'] > 0) {
                used[result.back() - 'a'] = false;
                result.pop_back();
            }

            result.push_back(c);
            used[c - 'a'] = true;
        }

        return result;
    }
};
