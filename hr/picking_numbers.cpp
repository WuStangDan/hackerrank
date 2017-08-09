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


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    int max_set = 0;
    for (int i = 0; i < a.size(); i++) {
        int count_above = 0;
        int count_below = 0;
        int count = 0;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] - a[i] == 0) {
                count += 1;
            } else if (a[i] - a[j] == -1) {
                count_below += 1;
            } else if (a[i] - a[j] == 1) {
                count_above += 1;
            }
        }
        
        if (count_above > count_below) {
            count += count_above;
        } else {
            count += count_below;
        }
        
        if (count > max_set) {
            max_set = count;
        }
    }
    
    cout << max_set;
    
    return 0;
}
