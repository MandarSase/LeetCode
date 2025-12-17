class Solution {
public:
    char findTheDifference(string s, string t) {
        string str;
        char ans=0;
        str=s+t;
        for(char c : str){
            ans^=c;
        }
        

        return tolower(ans);
    }
};