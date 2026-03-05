class Solution {
public:
    int minOperations(string s) {

        int n = s.size();

        string a = ""; // 010101...
        string b = ""; // 101010...

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                a += '0';
                b += '1';
            } else {
                a += '1';
                b += '0';
            }
        }

        int count1 = 0, count2 = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] != a[i])
                count1++;

            if(s[i] != b[i])
                count2++;
        }

        return min(count1, count2);
    }
};