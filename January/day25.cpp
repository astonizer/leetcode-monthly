class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() > 1 && arr[0] > arr[1]) return false;
        bool peakTraversed = false;
        for(int i=1; i<arr.size(); i++) {
            if(arr[i-1] < arr[i] && peakTraversed) 
                return false;
            else if(i>1 && arr[i-1] > arr[i] && !peakTraversed)
                peakTraversed = !peakTraversed;
            else if(arr[i-1] == arr[i])
                return false;
        }
        return peakTraversed;
    }
};
