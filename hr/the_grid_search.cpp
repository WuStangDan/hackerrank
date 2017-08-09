#include <bits/stdc++.h>

using namespace std;

bool TheGridSearch(vector<string> &, vector<string> &);

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++){
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++){
           cin >> P[P_i];
        }

        bool ans =  TheGridSearch(G, P);
        if (ans) {
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

bool TheGridSearch(vector<string> &m, vector<string> &k)
{
    int m_r, m_c, k_r_max, k_c_max, k_r = 0, k_c = 0;

    m_r = m.size();
    m_c = m[0].length();
    k_r_max = k.size();
    k_c_max = k[0].length();

    int m_temp, k_temp, i_hold, j_hold;
    for (int i = 0; i < m_r; i++) {
        for (int j = 0; j < m_c; j++) {
            m_temp = m[i][j] - '0';
            k_temp = k[k_r][k_c] - '0';

            if (m_temp == k_temp) {
                if (k_r == 0 && k_c == 0) {
                    // Set place holders to come back to.
                    i_hold = i;
                    j_hold = j+1;
                }
                //cout << "Match at " << i << " " << j << " ";
                //cout << "Ks " << k_r << " " << k_c << endl;
                k_c += 1;
                // Check if done row.
                if (k_c == k_c_max) {
                    //cout << "New row" << endl;
                    k_r += 1;
                    k_c = 0;
                    j -= k_c_max; // J will increment by one on its own so don't need k_c_max-1.
                    i +=1;
                    if (k_r == k_r_max) return true;
                }
            } else {
                if (k_c != 0) {
                    i = i_hold;
                    j = j_hold;
                }
                k_r = k_c = 0;
            }
        }
    }
    return false;
}
