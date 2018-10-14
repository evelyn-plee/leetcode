/** BruteForce **/


class Solution {
public:
    string nextClosestTime(string time) {
        set<char> s(time.begin(), time.end());
        int hour = stoi(time.substr(0,2));
        int min = stoi(time.substr(3,2));
        while(true){
            if(++min == 60){
                min = 0;
                (++hour) %= 24;
            }
            char buffer[5];
            sprintf(buffer, "%02d:%02d", hour, min);
            set<char> s2(buffer, buffer+sizeof(buffer));
            if(includes(s.begin(), s.end(), s2.begin(), s2.end()))
                return string(buffer);
        }
        return time;
    }
};
