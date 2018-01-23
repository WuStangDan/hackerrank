class Solution {
public:
    vector<TreeNode*> nextline(vector<TreeNode*> currentline, bool move_right) {
        vector<TreeNode*> newline;
        for (int i = currentline.size()-1; i >= 0; i--) {
            if (move_right) {
                if (currentline[i]->left != NULL) {
                    newline.push_back(currentline[i]->left);
                }
                if (currentline[i]->right != NULL) {
                    newline.push_back(currentline[i]->right);
                }
            } else {
                if (currentline[i]->right != NULL) {
                    newline.push_back(currentline[i]->right);
                }
                if (currentline[i]->left != NULL) {
                    newline.push_back(currentline[i]->left);
                }
            }
        }
        return newline;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;

        vector<TreeNode*> input;

        input.push_back(root);
        bool direction = false;

        if (root == NULL) {
            return out;
        }

        while (!input.empty()) {
            vector<int> line;
            for (int i = 0; i < input.size(); i++) {
                line.push_back(input[i]->val);
            }
            out.push_back(line);
            input = nextline(input, direction);
            if (direction == true) {
                direction = false;
            } else {
                direction = true;
            }
        }

        return out;
    }
};
