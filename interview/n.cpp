
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// hello => lleho
// robot => oobrt
// generally => eellagnry
string frequencySortedString(string s) {
    // for each char in alphabet
    // store count of char in st
    vector<int> map;  // map['a'] += 1
    map.resize(256);

    string output;

    for (int i = 0; i < s.length(); i++) {
        map[s[i]] += 1;
    }
    // map = { 'g': 1, 'e': 2, 'n': 1, 'l': 2, .. }
    while (true) {
        int max_count = 0;
        vector<char> letter;
        for (int i = 0; i < 256; ++i) {
            if(max_count < map[i]) {
                max_count = map[i];

                letter.clear();
                letter.push_back(i);
            } else if (max_count == map[i]) {
                letter.push_back(i);
            }
        }


        // sort letter.

        std::sort(letter.begin(), letter.end());
        // rbt => brt
        for (int i = 0; i < letter.size(); i++) {
            for (int j = 0; j < max_count; j++) {
                output.insert(output.end(), letter[i]);
            }

            map[letter[i]] = 0;
        }

        if (max_count == 0) break;
        // remove char letters from the map.
    }

    return output;
}


int main() {
    cout << frequencySortedString("generally");
    return 0;
}
