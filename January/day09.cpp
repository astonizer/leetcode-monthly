class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x = 0, y = 0, rot = 0;
        int i[] = {0, -1, 0, 1};
        int j[] = {1, 0, -1, 0};
        for(char c: instructions) {
            if(c == 'L') {
                rot = (rot + 1) % 4;
            } else if(c == 'R') {
                rot = (rot + 3) % 4;
            } else {
                x += i[rot];
                y += j[rot];
            }
        }
        return (x==0 && y==0) || rot;
    }
};
