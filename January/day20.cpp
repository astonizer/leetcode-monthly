class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int hrs) {
        int l = 1, h = 1e9;
        while(l < h) {
            int m = l + ((h-l)>>1);
            int k = 0;
            
            for(int pile: piles)
                k += (pile+m-1)/m;
            
            if(k <= hrs) 
                h = m;
            else 
                l = m + 1;
        }
        return l;
    }
};
