class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while(i<n && s[i] == ' ') i++;
        
        long ans = 0, isNeg = 0;
        if(s[i] == '-') isNeg = 1, i++;
        else if(s[i] == '+') i++;
        
        while(i<n && s[i]>='0' && s[i]<='9') {
            int d = s[i] - '0';
            ans = ans*10 + d;
            
            if(ans > INT_MAX) 
                return isNeg?INT_MIN:INT_MAX;
            
            i++;
        }
        if(isNeg)
            ans = -ans;
        if(ans < INT_MIN)
            return INT_MIN;
        return ans;
    }
};
