class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        unordered_map<int, int> data;
        return coinLoop(coins, amount, data, true);
    }

    int coinLoop(vector<int> &coins, int amount, unordered_map<int, int> &data, bool print=false) {
        if (data.count(amount) != 0) {
            //if (data[amount] == 0) cout << "ZERO" << endl;
            return data[amount];
        }
        for (int i = coins.size()-1; i >= 0; i--) {
            if (amount - coins[i] == 0) {
                return 1;
            }
        }
        vector<int> ans;
        for (int i = coins.size()-1; i >= 0; i--) {
            if (amount - coins[i] > 0) {
                int temp = coinLoop(coins,amount-coins[i], data);
                if (temp == -1) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(temp+1);
                }
            }
        }
        if (ans.size() == 0) return -1;
        if (ans.size() == 1) return ans[0];
        int min;
        bool found_min = false;

        for (int i = 0; i < ans.size(); i++) {
            if (print == true) {
                cout << ans[i] << " ";
            }
            if (found_min == false && ans[i] > 0) {
                min = ans[i];
                found_min = true;
            }
            if (min > ans[i] && ans[i] > 0 && found_min == true) {
                min = ans[i];
            }
        }

        if (found_min == false) {
            data[amount] = -1;
            return -1;
        }
        data[amount] = min;
        return min;
    }
};
