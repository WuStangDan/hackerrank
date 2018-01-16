class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bag = 0;
        int buy_price = -1;
        bool hodl = false;
        for (int i = 1; i < prices.size(); i++) {
            if (hodl == true) {
                if (prices[i-1] > prices[i]) {
                    // Sell
                    bag += prices[i-1] - buy_price;
                    cout << "sell " << prices[i-1] << endl;
                    hodl = false;
                }
            }
            if (hodl == false) {
                if (prices[i-1] < prices[i]) {
                    // Buy
                    buy_price = prices[i-1];
                    cout << "buy " << buy_price << endl;
                    hodl = true;
                }

            }
            if (hodl == true) {
                if (i+1 >= prices.size()) {
                    bag += prices[i] - buy_price;
                    return bag;
                }
            }
        }
        return bag;
    }
};
