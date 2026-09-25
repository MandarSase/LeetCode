class Solution {
public:
    int countDigits(int num) {
    vector<int> digits;
    int count=0;

    for (char c : to_string(num)) {
            digits.push_back(c - '0');
    }
    for(int digit : digits){
        if(num%digit==0) count++;
    }
return count;  

                    
    }
};