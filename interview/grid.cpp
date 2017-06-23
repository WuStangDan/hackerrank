// I encountered a problem similar to this during an interview for Drive.ai.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void PrintGrid(vector<vector<int> > );

void CombineGridPoints(vector<vector<int> > const &, vector<vector<int> >&);

void FindCombine(vector<vector<int> > const &, vector<vector<int> >&, int , int, int);

void RemoveSmallMatch( vector<vector<int> > &);

int main()
{
  int grid_size = 10;

  vector<vector<int> > grid(grid_size, vector<int>(grid_size,0));
  vector<vector<int> > match(grid_size, vector<int>(grid_size,0));

  // Set matrix to be used for the test.
  grid[1][1] = 9;
  grid[1][2] = 6;
  grid[2][1] = 9;
  grid[2][2] = 9;
  grid[2][3] = 7;


  grid[8][7] = 1;
  grid[8][6] = 1;
  grid[9][6] = 1;
  grid[9][7] = 1;
  grid[7][7] = 1;
  grid[6][7] = 1;
  grid[5][7] = 1;
  grid[5][8] = 1;
  grid[5][9] = 1;
  grid[4][9] = 1;
  grid[3][9] = 1;
  grid[4][7] = 1;
  grid[4][6] = 1;
  grid[3][6] = 1;
  grid[3][7] = 1;


  cout << "Individual Points Start";
  PrintGrid(grid);

  cout << "Combined Start";
  PrintGrid(match);

  CombineGridPoints(grid, match);

  cout << "Individual Points";
  PrintGrid(grid);

  cout << "Combined";
  PrintGrid(match);
}

void PrintGrid(vector<vector<int> > m)
{
  int r = m.size();
  int c = m[0].size();

  cout << endl << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;
}

void CombineGridPoints(vector<vector<int> > const &pts, vector<vector<int> > &comb)
{
  // Scan through entire grid until non zero value is found.
  int match_num = 1;
  for (int r = 0; r < pts.size(); r++) {
    for (int c = 0; c < pts[0].size(); c++) {
      // If point on grid is non zero and it hasn't already accounted in comb,
      // begin method of combining and finding all other points.
      if (pts[r][c] != 0 && comb[r][c] == 0) {
        cout << "Found at " << r << " " << c << " Starting num " << match_num
        << endl << endl;
        comb[r][c] = match_num;
        FindCombine(pts, comb, r, c, match_num);
        cout << "Finished num " << match_num << endl << endl;
        match_num += 1;
      }
    }
  }

  RemoveSmallMatch(comb);

}

void FindCombine(vector<vector<int> > const &pts, vector<vector<int> > &comb, int r , int c,
  int match_num)
{
  int match_range = 2; // Absolute difference between two numbers must be
  // less than or equal to this range.

  cout << "Entering at " << r << " " << c << endl;
  vector<vector<int> > search_area;
  int r_max = pts.size();
  int c_max = pts[0].size();


  vector<int> v(2);
  // Add all valid surronding locations to search_area.
  for (int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++) {
      // Skip middle location.
      if (!(i == 0 && j == 0)) {
        v[0] = r+i;
        v[1] = c+j;
        // Filter out any out of bounds areas.
        if (v[0] >= 0 && v[0] <  r_max) {
          if (v[1] >= 0 && v[1] < c_max) {
            search_area.push_back(v);
          }
        }
      }
    }
  }


  for (int i = 0; i < search_area.size(); i++) {
    v = search_area[i];
    int r_test = search_area[i][0];
    int c_test = search_area[i][1];
    // Test to see if any surronding points are non zero and not yet in comb.
    if (pts[r_test][c_test] != 0 && comb[r_test][c_test] == 0) {
      // Test to see if any surronding points are within a set range.
      if (abs(pts[r_test][c_test] - pts[r][c]) <= match_range) {
        cout << "Found at " << r_test << " " << c_test << endl;
        comb[r_test][c_test] = match_num;
        FindCombine(pts, comb, r_test, c_test, match_num);
      }
    }
  }

  cout << "Exiting at " << r << " " << c << endl;
}

void RemoveSmallMatch( vector<vector<int> > &comb)
{
  int combine_min_count = 4;
  // Count all match nums to remove any numbers that don't have enough points.
  unordered_map<int, int> match_count; // <match_num, count>
  for (int r = 0; r < comb.size(); r++) {
    for (int c = 0; c < comb[0].size(); c++) {
      if (comb[r][c] != 0) {
        if (match_count.count(comb[r][c]) == 0) {
          match_count[comb[r][c]] = 1;
        } else {
          match_count[comb[r][c]] += 1;
        }
      }
    }
  }

  // Go through grid again and remove all matches.
  for (int r = 0; r < comb.size(); r++) {
    for (int c = 0; c < comb[0].size(); c++) {
      if (match_count.count(comb[r][c]) != 0) {
        // See if match meets minimum count.
        if (match_count[comb[r][c]] < combine_min_count) {
          // Remove that match number.
          comb[r][c] = 0;
        }
      }
    }
  }
}
