#include <bits/stdc++.h>

using namespace std;

int saveThePrisoner(unsigned long int n, unsigned long int m, unsigned long int s){
    // m can now be added to s to get last sweet id.
    m -= 1;
    // If more sweets than prisoners.
    if (m >= n) {
      m = m % n;
    }

    s += m;

    if (s > n) {
      s = s % n;
    }

    return s;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        unsigned long int n;
        unsigned long int m;
        unsigned long int s;
        cin >> n >> m >> s;
        unsigned long int result = saveThePrisoner(n, m, s);
        cout << result << endl;
    }
    return 0;
}
