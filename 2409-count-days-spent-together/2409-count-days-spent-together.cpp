class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int pre[13] = {0};
        for (int i = 0; i < 12; i++)
            pre[i + 1] = pre[i] + days[i];

        auto toDay = [&](const string& s) {
            int m = stoi(s.substr(0, 2));
            int d = stoi(s.substr(3, 2));
            return pre[m - 1] + d;
        };

        int start = max(toDay(arriveAlice), toDay(arriveBob));
        int end = min(toDay(leaveAlice), toDay(leaveBob));
        return max(0, end - start + 1);
    }
};