/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //判断当前分支是否是镜像对称的
bool recursion(struct TreeNode* left, struct TreeNode* right) {
    if (left == NULL && right == NULL) {
        return true;
    }
    else if (left == NULL || right == NULL) {
        return false;
    }

    bool c1 = (left->val == right->val);
    bool c2 = recursion(left->left, right->right);
    bool c3 = recursion(left->right, right->left);
    if (c1 && c2 && c3) {
        return true;
    }
    else {
        return false;
    }
}

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;
    }
    return recursion(root->left, root->right);
}