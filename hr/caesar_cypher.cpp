#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Hacker rank - Caesar Cipher

Goal: Cypher the text by shifting all letters by 2nd int amount.

input example:
11
middle-Outz
2

correct output example:
okffng-Qwvb
*/

int CharIsLetter(char );

int main() {
    int s_len, shift;
    string s;
    cin >> s_len >> s >> shift;

    // Move shift into range of 0 - 25.
    while (shift >= 25) {
        shift -= 26;
    }

    int temp_char;

    for (int i = 0; i < s_len; i++) {
        temp_char = s[i];
        // Upper or lowercase.
        int ans = CharIsLetter(temp_char);

        if (ans > 0) {
            temp_char = s[i];
            temp_char += shift;

            // If lowercase to start, check still lowercase.
            if (ans == 1) {
                if (temp_char > 122) {
                    temp_char -= 26;
                }
            // If uppercase, check that still uppercase.
            } else {
                if (temp_char > 90) {
                    temp_char -= 26;
                }
            }
            s[i] = temp_char;
        }
    }

    cout << s;
}

int CharIsLetter(char check)
{
    int char_num = check;

    // Check if char is lower case.
    if (char_num >= 97 && char_num <= 122)
    {
        return 1; // 1 for lowercase.
    } else {
        if (char_num >= 65 && char_num <= 90) {
            return 2; // 2 for uppercase.
        } else {
            return 0; // 0 for not letter.
        }
    }
}
