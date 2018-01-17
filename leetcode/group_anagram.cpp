#include <iomanip>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int words = strs.size();
        vector<vector<string>> ans;

        while (strs.size() > 0) {
            vector<string> temp;
            if (strs.size() == 1) {
                temp.push_back(strs[0]);
                ans.push_back(temp);
                return ans;
            }
            temp.push_back(strs[strs.size()-1]);
            strs.pop_back();
            for (int i = strs.size()-1; i >= 0; i--) {
                if (strs[i].size() != temp[0].size()) {
                    continue;
                }
                if (isAnagram(temp[0], strs[i]) == true) {
                    temp.push_back(strs[i]);
                    strs.erase(strs.begin()+i);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
    bool isAnagram(string root, string compare) {
        for (int i = 0; i < root.size(); i++) {
            bool match = false;
            for (int j = 0; j < compare.size(); j++) {
                //cout << root[i] << " = " << compare[j];
                if (root[i] == compare[j]) {
                    match = true;
                    compare.erase(compare.begin()+j);
                    //cout << " match" << endl;
                    break;
                }
                //cout << endl;
            }
            if (match == false) {
                //cout << "false" << endl;
                return false;
            }
        }
        return true;
    }
};
