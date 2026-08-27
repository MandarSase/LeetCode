class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int c[26] = {};
        for(char x:s) c[x-'a']++;

        string ans;
        for(int i=0;i<s.size();i++) {
            int x=t[i]-'a';
            if(c[x]) {
                ans+=t[i];
                c[x]--;
            } else {
                for(int j=x+1;j<26;j++) if(c[j]) {
                    ans+=char('a'+j);
                    c[j]--;
                    for(int k=0;k<26;k++)
                        ans+=string(c[k],char('a'+k));
                    return ans;
                }
                break;
            }
        }

        while(!ans.empty()) {
            int x=ans.back()-'a';
            ans.pop_back();
            c[x]++;

            for(int j=x+1;j<26;j++) if(c[j]) {
                ans+=char('a'+j);
                c[j]--;
                for(int k=0;k<26;k++)
                    ans+=string(c[k],char('a'+k));
                return ans;
            }
        }

        return "";
    }
};