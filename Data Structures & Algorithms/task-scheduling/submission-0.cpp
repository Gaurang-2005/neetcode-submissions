class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char, int> freq;

        for (char task : tasks) {
            freq[task]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &[task, count] : freq) {
            pq.push({count, task});
        }

        queue<tuple<char, int, int>> cooldown;

        int time = 0;

        while (!pq.empty() || !cooldown.empty()) {

            while (!cooldown.empty() &&
                   get<2>(cooldown.front()) <= time) {

                auto [task, count, availableTime] =
                    cooldown.front();

                cooldown.pop();

                pq.push({count, task});
            }

            if (!pq.empty()) {

                auto [count, task] = pq.top();
                pq.pop();

                count--;

                if (count > 0) {
                    cooldown.push({
                        task,
                        count,
                        time + n + 1
                    });
                }
            }

            time++;
        }

        return time;
    }
};