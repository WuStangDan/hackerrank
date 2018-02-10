class Graph {
    public:
        Graph(int n) {
            nodes = n;
            vector<int> rows(n, -1);
            for (int i = 0; i < n; i++) {
                grid.push_back(rows);
                ans.push_back(-1);
            }

        }

        void add_edge(int u, int v) {
            grid[u][v] = v;
            grid[v][u] = u;
            return;
        }



        vector<int> shortest_reach(int start) {
            // Find all options from start.
            int count = 1;
            AddConnectionsToQue(start, count);

            while (next.size() > 0) {
                count += 1;
                current = next;
                while (!next.empty()) next.pop();

                while (current.size() > 0) {
                    int check = current.front();
                    current.pop();
                    AddConnectionsToQue(check, count);
                }
                //cout << "next size" << next.size() << endl;
            }
            // Add all these options to queue.
            // Match all found with ans to reach.
            // go through entire que finding all options.
            return ans;
        }


        void AddConnectionsToQue(int start, int dist) {
            for (int i = 0; i < nodes; i++) {
                //cout << grid[start][i] << endl;
                if (grid[start][i] != -1) {
                    if (visted[grid[start][i]] != 1) {
                        next.push(grid[start][i]);
                        visted[grid[start][i]] = 1;
                        ans[i] = 6*dist;
                    }
                }
            }
        }
    private:
        int nodes;
        vector<int> ans;
        unordered_map<int, int> visted;
        vector<vector<int>> grid;
        queue<int> current;
        queue<int> next;

};
