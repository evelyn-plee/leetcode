class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int n = timePoints.size(), res = 24*60;
        for(int i = 0; i < n; i++){
            int timeDiff = diff(timePoints[i], timePoints[(i+1)%n]);
            timeDiff = min(timeDiff, 1440-timeDiff);
            res = min(timeDiff, res);
        }
        return res;
    }

private:
    int diff(string t1, string t2){
        int h1 = stoi(t1.substr(0,2));
        int m1 = stoi(t1.substr(3,5));
        int h2 = stoi(t2.substr(0,2));   
        int m2 = stoi(t2.substr(3,5));
        return abs((h1-h2)*60 + (m1-m2));
    }
};
