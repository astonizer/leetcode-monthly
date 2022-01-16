class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size(), ans = 0;
        vector<int> person;
        for(int i=0; i<n; i++) {
            if(seats[i]) {
                person.push_back(i);
            }
        }
        int m = person.size();
        if(seats[0] == 0) 
            ans = max(ans, person[0]);
        if(seats[n-1] == 0) 
            ans = max(ans, n - 1 - person[m-1]);
        for(int i=1; i<m; i++) {
            ans = max(
                ans,
                (person[i] - person[i-1])/2
            );
        }
        return ans;
    }
};
