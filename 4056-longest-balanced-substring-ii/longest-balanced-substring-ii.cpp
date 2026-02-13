#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    
    int calc1(string &s) {
        int res = 0;
        int i = 0, n = s.size();
        
        while (i < n) {
            int j = i + 1;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            res = max(res, j - i);
            i = j;
        }
        return res;
    }
    
    
    int calc2(string &s, char a, char b) {
        int res = 0;
        int i = 0, n = s.size();
        
        while (i < n) {
            while (i < n && s[i] != a && s[i] != b) {
                i++;
            }
            
            unordered_map<int, int> pos;
            pos[0] = i - 1;
            int d = 0;
            
            while (i < n && (s[i] == a || s[i] == b)) {
                if (s[i] == a) d++;
                else d--;
                
                if (pos.count(d)) {
                    res = max(res, i - pos[d]);
                } else {
                    pos[d] = i;
                }
                i++;
            }
        }
        return res;
    }
    
    
    int calc3(string &s) {
        unordered_map<long long, int> pos;
        pos[0] = -1; 
        
        int a = 0, b = 0, c = 0;
        int res = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else c++;
            
            int diffAB = a - b;
            int diffBC = b - c;
            
            long long key = ((long long)diffAB << 32) | (diffBC & 0xffffffffLL);
            
            if (pos.count(key)) {
                res = max(res, i - pos[key]);
            } else {
                pos[key] = i;
            }
        }
        return res;
    }
    
    int longestBalanced(string s) {
        int x = calc1(s);
        
        int y = max({
            calc2(s, 'a', 'b'),
            calc2(s, 'b', 'c'),
            calc2(s, 'a', 'c')
        });
        
        int z = calc3(s);
        
        return max({x, y, z});
    }
};
