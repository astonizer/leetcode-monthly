class Solution {
public:
    string addBinary(string a, string b) {
        // equalizing length
        while(a.length() < b.length()) a.insert(0, "0");
        while(a.length() > b.length()) b.insert(0, "0");
        
        int n = a.length(), m = b.length();
        int carry = 0;
        for(int i=n-1; i>=0; i--) {
            int sum = a[i] - '0' + b[i] - '0';
            a[i] = (sum + carry) % 2 + '0';
            carry = (sum + carry) / 2;
        }
        if(carry) {
            a.insert(0, "1");
        }
        return a;
    }
};
