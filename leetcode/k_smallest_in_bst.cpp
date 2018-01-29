class Solution {
public:
    vector<int> smallest2(TreeNode* root, int k) {
        vector<int> ans;
        ans.push_back(root->val);

        vector<int> vleft;
        if (root->left != NULL) {
            vleft = smallest2(root->left, k);
        }
        vector<int> vright;
        if (root->right != NULL) {
            vright = smallest2(root->right, k);
        }

        int ans_pos = 0;
        for (int i = 0; i < vleft.size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                if (vleft[i] < ans[j]) {
                    ans.insert(ans.begin()+j, vleft[i]);
                    break;
                } else {
                    if (j == ans.size()-1) {
                        ans.push_back(vleft[i]);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < vright.size(); i++) {
            for (int j = 0; j < ans.size(); j++) {
                if (vright[i] < ans[j]) {
                    ans.insert(ans.begin()+j, vright[i]);
                    break;
                } else {
                    if (j == ans.size()-1) {
                        ans.push_back(vright[i]);
                        break;
                    }
                }
            }
        }
        while(ans.size() > k) {
            ans.pop_back();
        }

        return ans;
    }
    int kthSmallest(TreeNode* root, int k) {
        // Implement DFS search all nodes need to be searched eventually.
        vector<int> small;
        small = smallest2(root, k);
        int ans;
        cout << "small size " << small.size() << endl;
        for (int i = 0; i < small.size(); i++) {
            cout << small[i] << " ";
            if (i == k-1) {
                ans = small[i];
            }
        }
        return ans;
    }
};
