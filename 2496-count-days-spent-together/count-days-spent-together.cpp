class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

        int a1 = stoi(arriveAlice.substr(0, 2));
        int a2 = stoi(arriveAlice.substr(3, 2));

        int l1 = stoi(leaveAlice.substr(0, 2));
        int l2 = stoi(leaveAlice.substr(3, 2));

        int b1 = stoi(arriveBob.substr(0, 2));
        int b2 = stoi(arriveBob.substr(3, 2));

        int r1 = stoi(leaveBob.substr(0, 2));
        int r2 = stoi(leaveBob.substr(3, 2));

        int aliceStart = days[a1 - 1] + a2;
        int aliceEnd = days[l1 - 1] + l2;

        int bobStart = days[b1 - 1] + b2;
        int bobEnd = days[r1 - 1] + r2;

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        if (start > end) {
            return 0;
        }

        return end - start + 1;
    }
};