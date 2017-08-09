#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool OnBoard(int n, int r, int c)
{
    if (r < 0 || c < 0) {
        return false;
    }
    if (r >= n || c >= n) {
        return false;
    }
    return true;
}

bool InMatrix(const int r, const int c, const vector<vector<int> > &m)
{
    for (int i = 0; i < m.size(); i++) {
        if (m[i][0] == r && m[i][1] == c) {
            return true;
        }
    }
    return false;
}


int main(){
    int n;
    int k;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;

    // Create matrix.
    vector<vector<int> > m;
    // Fill with obstacles.
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;

        int r_diff = abs(rQueen - rObstacle);
        int c_diff = abs(cQueen - cObstacle);
        // Don't add obstacles that aren't in the way to save time.
        if (r_diff == 0 || c_diff == 0) {
            vector<int> temp = {rObstacle-1, cObstacle-1};
            m.push_back(temp);
        } else if (r_diff == c_diff) {
            vector<int> temp = {rObstacle-1, cObstacle-1};
            m.push_back(temp);
        }
    }

    int count = 0;
    for (int r_mod = -1; r_mod <= 1; r_mod++) {
        for (int c_mod = -1; c_mod <= 1; c_mod++) {
            if (r_mod == 0 && c_mod == 0) continue;
            int r = rQueen-1, c = cQueen-1;
            r += r_mod;
            c += c_mod;
            while (OnBoard(n, r, c)) {
                if (!InMatrix(r, c, m)) {
                    count += 1;
                    r += r_mod;
                    c += c_mod;
                } else {
                    break;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}
