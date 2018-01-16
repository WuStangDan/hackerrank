class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        cout << findNums.size();
        vector<int> ans(findNums.size());
        for (int i = 0; i < findNums.size(); i++){
            for (int j = 0; j < nums.size(); j++) {
                if (findNums[i] == nums[j]){
                    ans[i] = nextGreatNum(findNums[i], nums, j);
                }
            }
        }
        return ans;
    }
    int nextGreatNum(int start_num, vector<int> &nums, int nums_loc) {
        for (int i = nums_loc+1; i < nums.size(); i ++) {
            if (nums[i] > start_num) {
                return nums[i];
            }
        }
        return -1;
    }
};
