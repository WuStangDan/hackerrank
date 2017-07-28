#include <bits/stdc++.h>

using namespace std;

int divisibleSumPairs(int n, int k, vector <int> ar) {
    int ans = 0;
    for (int j = 1; j < ar.size(); j++) {
        for (int i = 0; i < j; i++) {
            if (((ar[j] + ar[i]) % k) == 0) {
                ans += 1;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = divisibleSumPairs(n, k, ar);
    cout << result << endl;
    return 0;
}
