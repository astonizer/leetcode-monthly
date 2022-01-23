class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        int f = 0, cnt = 0, lo = low;
        while(low) {
            f = low%10;
            low = low / 10;
            cnt++;
        }
        while(low <= high && low <= INT_MAX/10) {
            low = 0;
            if(f + cnt > 10) f = 1, cnt++;
            int curr_d = f, curr_cnt = cnt;
            while(curr_cnt--)
                low = low*10 + curr_d++;
            if(lo <= low && low <= high) ans.push_back(low);
            f++;
        }
        return ans;
    }
};
