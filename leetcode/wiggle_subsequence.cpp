class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> wiggle;

        if (nums.size() < 2) {
            return nums.size();
        }

        wiggle.push_back(nums[0]);
        int diff_direction = 0;

        for (int i = 1; i < nums.size(); i++) {
            int w_last_index = wiggle.size()-1;
            if (nums[i] == wiggle[w_last_index]) {
                continue;
            } else if (nums[i] > wiggle[w_last_index]) {
                if (diff_direction != 1) {
                    wiggle.push_back(nums[i]);
                    diff_direction = 1;

                } else { // Find highest value in same chain to give
                        // best possible chance to find lower in next step.
                    wiggle[w_last_index] = nums[i];
                }
            } else { // nums[i] < wiggle[w_last_index]
                if (diff_direction != -1) {
                    wiggle.push_back(nums[i]);
                    diff_direction = -1;
                } else {
                    wiggle[w_last_index] = nums[i];
                }
            }
        }
        return wiggle.size();
    }
};
