/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    TreeNode *build(const vector<int> &preorder, const vector<int> &inorder, int pl, int pr, int il, int ir) {
      if (pl > pr) return NULL;
      TreeNode *res = new TreeNode(preorder[pl]);
      int pos = distance(inorder.begin(), find(inorder.begin(), inorder.end(), res->val));
      int left_size = pos - il, right_size = ir - pos - 1;
      res->left = build(preorder, inorder, pl + 1, pl + left_size, il, pos - 1);
      res->right = build(preorder, inorder, pl + left_size + 1, pr, pos + 1, ir);
      return res;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
      return build(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
