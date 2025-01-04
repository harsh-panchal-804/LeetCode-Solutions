/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        vector<int> level_sums;
        while (!node_queue.empty()) {
            int level_sum = 0;
            int level_size = node_queue.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode* current_node = node_queue.front();
                node_queue.pop();
                level_sum += current_node->val;
                if (current_node->left) node_queue.push(current_node->left);
                if (current_node->right) node_queue.push(current_node->right);
            }
            level_sums.push_back(level_sum);
        }

        node_queue.push(root);
        int level_index = 1;
        root->val = 0;
        while (!node_queue.empty()) {
            int level_size = node_queue.size();
            for (int i = 0; i < level_size; ++i) {
                TreeNode* current_node = node_queue.front();
                node_queue.pop();

                int sibling_sum =
                    (current_node->left ? current_node->left->val : 0) +
                    (current_node->right ? current_node->right->val : 0);

                if (current_node->left) {
                    current_node->left->val = level_sums[level_index] - sibling_sum;
                    node_queue.push(current_node->left);
                }
                if (current_node->right) {
                    current_node->right->val =
                        level_sums[level_index] - sibling_sum;
                    node_queue.push(current_node->right);
                }
            }
            ++level_index;
        }

        return root;
    }
};