class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int best = INT_MAX;

        for (int s : {1, -1}) {
            int c = nums[0];
            bool ok = true;
            for (int i = 0; i < n; i++) {
                int expect = ((s * i + c) % n + n) % n;
                if (nums[i] != expect) { ok = false; break; }
            }
            if (!ok) continue;

            vector<vector<int>> dist(2, vector<int>(n, -1));
            auto id = [&](int sg) { return sg == 1 ? 0 : 1; };
            queue<pair<int,int>> q;
            dist[id(s)][c] = 0;
            q.push({s, c});

            while (!q.empty()) {
                auto [sg, cc] = q.front(); q.pop();
                int d = dist[id(sg)][cc];
                if (sg == 1 && cc == 0) { best = min(best, d); break; }

                int c1 = ((cc + sg) % n + n) % n;
                if (dist[id(sg)][c1] == -1) {
                    dist[id(sg)][c1] = d + 1;
                    q.push({sg, c1});
                }

                int c2 = ((cc - sg) % n + n) % n;
                if (dist[id(-sg)][c2] == -1) {
                    dist[id(-sg)][c2] = d + 1;
                    q.push({-sg, c2});
                }
            }
        }
        return best == INT_MAX ? -1 : best;
    }
};