#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Hackerrank - Circular Array Rotation

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k, q;

    cin >> n >> k >> q;


    // Read input into array.
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Rotate array to the right by k.
    vector<int> a_temp = a;

    for (int i = 0; i < n; i++) {
        int shift = (i+k)%n;
        a[shift] = a_temp[i];
    }

    // Respond to queries.
    int q_num;
    for (int i = 0; i < q; i++) {
        cin >> q_num;
        cout << a[q_num] << endl;
    }

    return 0;
}
