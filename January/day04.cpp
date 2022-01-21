class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
            return 1;
        int bits = log2(n) + 1;
        return ((1<<bits) - 1)^n;
    }
};
