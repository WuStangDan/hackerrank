class NumArray {
public:
    NumArray(vector<int> nums) {
        v = nums;
    }

    void update(int i, int val) {
        v[i] = val;
    }

    int sumRange(int i, int j) {
        int sum = 0;
        for (int k = i; k <= j; k++) {
            sum += v[k];
        }
        return sum;

    }
private:
    vector<int> v;
};
