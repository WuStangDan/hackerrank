class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rows;
        vector<int> cols;

        for (int r = 0; r < matrix.size(); r++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                if (matrix[r][c] == 0) {
                    rows.push_back(r);
                    cols.push_back(c);
                }
            }
        }
        // Replace with zeros.
        for (int i = 0; i < rows.size(); i++) {
            for (int c = 0; c < matrix[0].size(); c++) {
                matrix[rows[i]][c] = 0;
            }
        }
        for (int i = 0; i < cols.size(); i++) {
            for (int r = 0; r < matrix.size(); r++) {
                matrix[r][cols[i]] = 0;
            }
        }
    }
};
