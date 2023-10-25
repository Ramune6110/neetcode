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
    // RECURSIVE DFS
    /*int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }*/

    // ITERATIVE DFS
    /*int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        stack<pair<TreeNode*, int>> s;
        s.push({root, 1});
        int res = 0;

        while (!s.empty()) {
            TreeNode* node = s.top().first;
            int depth = s.top().second;
            s.pop();

            if (node) {
                res = max(res, depth);
                s.push({node->left, depth + 1});
                s.push({node->right, depth + 1});
            }
        }

        return res;
    }*/

    // BFS（幅優先探索）
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        queue<TreeNode*> q;
        q.push(root);
        int res = 0;

        while (!q.empty()) {
            int qsize = q.size();

            for (int i = 0; i < qsize; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            res++;
        }

        return res;
    }
};