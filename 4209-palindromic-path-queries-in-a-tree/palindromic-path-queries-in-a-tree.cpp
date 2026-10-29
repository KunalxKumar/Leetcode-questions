class Solution {
public:
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
    vector<int> tin;
    vector<int> tout;
    vector<int> bit;
    int timer;

    int getMask(char c) {
        return 1 << (c - 'a');
    }

    void add(int pos, int val, int n) {
        while (pos <= n) {
            bit[pos] ^= val;
            pos += pos & -pos;
        }
    }

    void rangeXor(int l, int r, int val, int n) {
        add(l, val, n);
        add(r + 1, val, n);
    }

    int query(int pos) {
        int ans = 0;

        while (pos > 0) {
            ans ^= bit[pos];
            pos -= pos & -pos;
        }

        return ans;
    }

    void dfs(int u, int p, vector<vector<int>>& g) {
        tin[u] = ++timer;
        up[u][0] = p;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : g[u]) {
            if (v == p) {
                continue;
            }

            depth[v] = depth[u] + 1;
            dfs(v, u, g);
        }

        tout[u] = timer;
    }

    bool ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v) {
        if (ancestor(u, v)) {
            return u;
        }

        if (ancestor(v, u)) {
            return v;
        }

        for (int j = LOG - 1; j >= 0; j--) {
            if (!ancestor(up[u][j], v)) {
                u = up[u][j];
            }
        }

        return up[u][0];
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        LOG = 1;

        while ((1 << LOG) <= n) {
            LOG++;
        }

        vector<vector<int>> g(n);

        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        up.assign(n, vector<int>(LOG));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(n + 2, 0);

        timer = 0;

        dfs(0, 0, g);

        vector<int> current(n);

        for (int i = 0; i < n; i++) {
            current[i] = getMask(s[i]);
            rangeXor(tin[i], tout[i], current[i], n + 1);
        }

        vector<bool> answer;

        for (string &q : queries) {
            string type;
            int u;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                int oldMask = current[u];
                int newMask = getMask(c);

                int change = oldMask ^ newMask;

                if (change != 0) {
                    rangeXor(tin[u], tout[u], change, n + 1);
                    current[u] = newMask;
                }
            }
            else {
                int v;
                ss >> v;

                int w = lca(u, v);

                int maskU = query(tin[u]);
                int maskV = query(tin[v]);

                int pathMask = maskU ^ maskV ^ current[w];

                if ((pathMask & (pathMask - 1)) == 0) {
                    answer.push_back(true);
                }
                else {
                    answer.push_back(false);
                }
            }
        }

        return answer;
    }
};