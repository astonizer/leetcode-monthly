class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = -2;
        for(int r=0; r<flowerbed.size(); r++) {
            if(flowerbed[r]) {
                n -= (r - l - 2)/2;
                l = r;
            }
        }
        n -= (flowerbed.size() - l - 1)/2;
        return n<=0;
    }
};
