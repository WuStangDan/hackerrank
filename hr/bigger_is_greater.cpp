#include <cmath>  // 4,11,8,3
#include <cstdio> // 8,3,4,11
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string LexiGreater(const string s);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        string s;
        cin >> s;
        cout << LexiGreater(s) << endl;
    }
    return 0;
}

string LexiGreater(const string s)
{
    int s_len = s.length();
    string out = s;
    //cout << endl;
    // Read all values into a vector.
    vector <int> word;
    for (int i = 0; i < s_len; i++) {
        word.push_back(s[i]);
      //  cout << word[i] << " ";

    }
    //cout << endl << endl;

    // Check if any single character swap is available.
    for (int i = s_len-1; i > 1; i--) {
        if(word[i] > word[i-1]) {
            out[i] = s[i-1];
            out[i-1] = s[i];
            return out;
        }
    }
    // Means no single character swap was available.
    // Check if string is in perfect order.
    bool perfect_order = true;
    for (int i = 0; i < s_len-1; i++) {
        if (word[i] < word[i+1]) {
            perfect_order = false;
        }
    }

    if (perfect_order == false) {
        //cout << "Perfect order was false" << endl;
        // Put next highest character first, and rearrange the rest
        // in perfect order.
        int next_letter_index = 0;
        int next_letter = 999;
        for (int i = 1; i < s_len; i++) {
            //cout << "comparing " << word[0] << " " << word[i] << endl;
            if ((word[i] > word[0]) && (word[i] < next_letter)) {
                //cout << word[i] << " passed!" << endl;
                next_letter_index = i;
                next_letter = word[i];
            }
        }
        //cout << "next letter i num " << next_letter_index << " " << next_letter << endl;
        out[0] = s[next_letter_index];
        out[next_letter_index] = s[0];

        // Bubble sort on the rest of the values.
        for (int i = 0; i < s_len; i++) {
            for (int j = 1; j < s_len-1; j++) {
                if(out[j] > out[j+1]) {
                    int temp = out[j+1];
                    out[j+1] = out[j];
                    out[j] = temp;
                }
            }
        }
        return out;

    } else {
        return "no answer";
    }
}
