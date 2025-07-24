class Solution {
public:
    vector<vector<int>> tree;
    vector<int> subtreeXor;
    vector<int> parent;

    void dfs(int node, int par, vector<int>& nums) {
        subtreeXor[node] = nums[node];
        parent[node] = par;

        for (int nei : tree[node]) {
            if (nei == par) continue;
            dfs(nei, node, nums);
            subtreeXor[node] ^= subtreeXor[nei];
        }
    }

    bool isAncestor(int u, int v) {
        while (v != -1) {
            if (v == u) return true;
            v = parent[v];
        }
        return false;
    }

    int getScore(int a, int b, int c) {
        int maxV = max({a, b, c});
        int minV = min({a, b, c});
        return maxV - minV;
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        tree.assign(n, {});
        subtreeXor.resize(n);
        parent.assign(n, -1);

        // Step 1: Build tree
        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        // Step 2: DFS to compute subtreeXor and parent
        dfs(0, -1, nums);
        int totalXor = subtreeXor[0];

        // Step 3: Store all edges as (parent, child)
        vector<pair<int, int>> directedEdges;
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            if (parent[v] == u) {
                directedEdges.push_back({u, v});
            } else {
                directedEdges.push_back({v, u});
            }
        }

        // Step 4: Try all pairs of edge removals
        int minScore = INT_MAX;

        for (int i = 0; i < directedEdges.size(); i++) {
            int a = directedEdges[i].second;
            for (int j = i + 1; j < directedEdges.size(); j++) {
                int b = directedEdges[j].second;

                if (isAncestor(a, b)) {
                    int x = subtreeXor[b];
                    int y = subtreeXor[a] ^ subtreeXor[b];
                    int z = totalXor ^ subtreeXor[a];
                    minScore = min(minScore, getScore(x, y, z));
                }
                else if (isAncestor(b, a)) {
                    int x = subtreeXor[a];
                    int y = subtreeXor[b] ^ subtreeXor[a];
                    int z = totalXor ^ subtreeXor[b];
                    minScore = min(minScore, getScore(x, y, z));
                }
                else {
                    int x = subtreeXor[a];
                    int y = subtreeXor[b];
                    int z = totalXor ^ x ^ y;
                    minScore = min(minScore, getScore(x, y, z));
                }
            }
        }

        return minScore;
    }
};
