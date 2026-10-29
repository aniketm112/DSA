class Solution {
    int n, LOG;
    vector<int> tin, tout, depth, base, bit;
    vector<vector<int>> up;

    void upd(int i, int v) {
        for (i++; i <= n + 1; i += i & -i) bit[i] ^= v;
    }
    int qry(int i) {
        int r = 0;
        for (i++; i > 0; i -= i & -i) r ^= bit[i];
        return r;
    }
    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; k++)
            if (diff >> k & 1) a = up[k][a];
        if (a == b) return a;
        for (int k = LOG - 1; k >= 0; k--)
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        return up[0][a];
    }

public:
    vector<bool> palindromePath(int n_, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_;
        LOG = 1;
        while ((1 << LOG) < n) LOG++;

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        base.assign(n, 0);
        bit.assign(n + 2, 0);
        up.assign(LOG, vector<int>(n, 0));

        int timer = 0;
        vector<int> st, idx(n, 0);
        st.push_back(0);
        up[0][0] = 0;
        tin[0] = timer++;
        base[0] = 1 << (s[0] - 'a');
        while (!st.empty()) {
            int u = st.back();
            if (idx[u] < (int)adj[u].size()) {
                int v = adj[u][idx[u]++];
                if (v == up[0][u] && u != 0) continue;
                if (u == 0 && v == 0) continue;
                up[0][v] = u;
                depth[v] = depth[u] + 1;
                base[v] = base[u] ^ (1 << (s[v] - 'a'));
                tin[v] = timer++;
                st.push_back(v);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }
        for (int k = 1; k < LOG; k++)
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][up[k - 1][i]];

        auto get = [&](int u) { return base[u] ^ qry(tin[u]); };

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;
            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;
                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));
                if (delta) {
                    upd(tin[u], delta);
                    upd(tout[u] + 1, delta);
                }
                s[u] = c;
            } else {
                int u, v;
                ss >> u >> v;
                int l = lca(u, v);
                int mask = get(u) ^ get(v) ^ (1 << (s[l] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};