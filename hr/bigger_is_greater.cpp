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
    //cout << "Input ";
    for (int i = 0; i < s_len; i++) {
        word.push_back(s[i]);
        //cout << word[i]-96 << " ";

    }
    //cout << endl << endl;

    // Check if string is in perfect order.
    bool perfect_order = true;
    for (int i = 0; i < s_len-1; i++) {
        if (word[i] < word[i+1]) {
            perfect_order = false;
        }
    }

    if (perfect_order == false) {

        // Moving i from right to left. If there is an i where there is a letter to the right
        // greater than i, find the lowest number that is greater than i.

        int min_letter_greater = 999;
        int min_letter_index;
        int replaced_letter_index;
        for (int i = s_len-2; i >= 0; i--) {
            bool greater_found = false;

            for (int j = i+1; j < s_len; j++) {
                if (word[j] > word[i] && word[j] < min_letter_greater) {
                    min_letter_greater = word[j];
                    min_letter_index = j;
                    greater_found = true;
                }
            }
            if (greater_found == true) {
                replaced_letter_index = i;
                break;
            }
        }

        // Swap replaced letter with lowest letter that is greater than it.
        out[replaced_letter_index] = s[min_letter_index];
        out[min_letter_index] = s[replaced_letter_index];


        // Bubble sort on the rest of the values.
        for (int i = replaced_letter_index; i < s_len; i++) {
            for (int j = replaced_letter_index+1; j < s_len-1; j++) {
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
