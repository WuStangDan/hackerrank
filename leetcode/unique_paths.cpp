class Solution {
public:
    int stackint(int m, int n) {
        return m*100+n;
    }
    int uniquePaths(int m, int n) {
        unordered_map<int, int> data;
        return uniqueLoop(m, n, data);
    }


    int uniqueLoop(int m, int n, unordered_map<int, int> &data){
        if (m == 1 || n == 1) return 1;
        int ans = 0;
        if (n >= 2){
            if (data.count(stackint(m,n-1))== 0) {
                ans += uniqueLoop(m,n-1, data);
                data[stackint(m,n-1)] = ans;
            } else {
                ans += data[stackint(m,n-1)];
            }
        }
        if (m >= 2) {
            if (data.count(stackint(m-1,n)) == 0) {
                int temp = uniqueLoop(m-1,n, data);
                data[stackint(m-1,n)] = temp;
                ans += temp;
            } else {
                ans += data[stackint(m,n-1)];
            }
        }
        return ans;
    }
};
