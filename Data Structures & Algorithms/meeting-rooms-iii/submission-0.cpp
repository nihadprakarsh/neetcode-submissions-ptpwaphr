class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        priority_queue<int, vector<int>, greater<>> availableRooms;
        for (int i = 0; i < n; ++i) availableRooms.push(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> occupiedRooms;

        for (auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }
            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({end, room});
                count[room]++;
            } else {
                auto [endTime, room] = occupiedRooms.top();
                occupiedRooms.pop();
                long long newEnd = endTime + (end - start);
                occupiedRooms.push({newEnd, room});
                count[room]++;
            }
        }

        int maxMeetings = -1, answer = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                answer = i;
            }
        }
        return answer;
    }
};