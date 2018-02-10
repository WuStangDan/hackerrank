int RegionSize(vector<vector<int>>& grid, int r_start, int c_start) {
    if (grid[r_start][c_start] != 1) return 0;
    int total = 1;
    grid[r_start][c_start] = 9;

    for (int r = r_start-1; r <= r_start+1; r++) {
        for (int c = c_start-1; c<= c_start+1; c++) {
            if (r < 0 || r >= grid.size()) continue;
            if (c < 0 || c >= grid[0].size()) continue;
            total += RegionSize(grid, r, c);
        }
    }
    return total;

}

int get_biggest_region(vector< vector<int> > grid) {
    int max = 0;
    for (int r = 0; r < grid.size(); r++) {
        for (int c = 0; c < grid[0].size(); c++) {
            int size = RegionSize(grid, r, c);
            if (size > max) max = size;
        }
    }
    return max;
}
