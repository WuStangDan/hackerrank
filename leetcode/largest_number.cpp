class Solution {
public:
    string largestNumber(vector<int>& nums) {

        string output;

        while (nums.size() > 0) {
            output = AddLargest(nums, output);
        }

        return output;
    }

    // Add largest value in nums to string, and remove from nums.
    string AddLargest(vector<int> &nums, string output) {

        string max_num_str = "-1";
        int max_num_index;

        for (int i = 0; i < nums.size(); i++) {
            string num = to_string(nums[i]);

            if (num[0] > max_num_str[0]) {
                max_num_index = i;
                max_num_str = num;
            } else if (num[0] == max_num_str[0]) {
                // Compare remaining digits.
                // If one continues, next digit has to be greater than current max.
                if (num.length() > max_num_str.length()) {
                    for (int j = 0; j < num.length(); j++) {
                        if (j-max_num_str.length() == 0) {
                            if ( num[j] > max_num_str[0]) {
                                max_num_str = num;
                                max_num_index = i;
                                break;
                            }
                        } else {
                            if (num[j] > max_num_str[j]) {
                                max_num_str = num;
                                max_num_index = i;
                                break;
                            } else if (max_num_str[j] > num[j]) {
                                break;
                            }
                        }
                    }
                } else {
                    for (int j = 0; j < max_num_str.length(); j++) {
                        if (j - num.length() == 0) {
                            if (num[0] > max_num_str[j]) {
                                max_num_str = num;
                                max_num_index = i;
                                break;
                            }
                        } else {
                            if (num[j] > max_num_str[j]) {
                                max_num_str = num;
                                max_num_index = i;
                                break;
                            } else if (max_num_str[j] > num[j]) {
                                break;
                            }
                        }
                    }
                }
            }

        }
        nums.erase(nums.begin()+max_num_index);
        return output + max_num_str;
    }
};
