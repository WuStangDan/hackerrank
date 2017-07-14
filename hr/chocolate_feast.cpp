#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int TripsToStore(const int, const int, const int);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int question_num;
    cin >> question_num;
    for (int i = 0; i < question_num; i++) {
        int n, c, m;
        cin >> n >> c >> m;

        cout << TripsToStore(n, c, m) << endl;
    }
    return 0;
}

int TripsToStore(const int n, const int c, const int m)
{
    int choc_ate = 0;
    if (n > c) {
        choc_ate = n/c;
        int wrappers = choc_ate;

        // While there are still enough wrappers to purchase
        // more chocolate.
        while(wrappers >= m) {
            // This takes advantage of int's auto rounding down.
            int wrapper_choc = wrappers/m;
            wrappers += wrapper_choc - wrapper_choc*m;

            choc_ate += wrapper_choc;
        }

        return choc_ate;
    } else {
        return choc_ate;
    }
}
