/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        // Copy list in vector form.
        vector<int> labels;
        vector<RandomListNode*> rands;
        vector<int> rands_pos;

        RandomListNode* loc = head;
        labels.push_back(loc->label);
        rands.push_back(loc);
        rands_pos.push_back(-1);

        cout << "Randoms" << endl;
        cout << loc->random << endl;

        while (loc->next != NULL) {
            loc = loc->next;
            labels.push_back(loc->label);
            rands.push_back(loc);
            rands_pos.push_back(-1);

            cout << loc->random << endl;
        }
        cout << endl;

        // Search for rand matches.
        loc = head;
        for (int j = 0; j < labels.size(); j++) {
            cout << loc->random << endl;
            if (loc->random == NULL) {
                loc = loc->next;
                continue;
            }
            for (int i = 0; i < rands.size(); i++) {
                if (loc->random == rands[i]) {
                    rands_pos[j] = i;
                    break;
                }
            }
            if (j == labels.size()-1) break;
            loc = loc->next;
        }
        cout << endl;


        // Create new copy.
        vector<RandomListNode*> new_pts;
        RandomListNode* head_ans = new RandomListNode(labels[0]);
        RandomListNode* ans_loc = head_ans;
        new_pts.push_back(head_ans);
        for (int i = 1; i < labels.size(); i++) {
            ans_loc->next = new RandomListNode(labels[i]);
            ans_loc = ans_loc->next;
            new_pts.push_back(ans_loc);
        }

        // Add randoms.
        for (int i = 0; i < rands_pos.size(); i++) {
            int pos = rands_pos[i];
            if (pos == -1) new_pts[i]->random = NULL;
            else new_pts[i]->random = new_pts[pos];
        }
        return new_pts[0];
    }
};
