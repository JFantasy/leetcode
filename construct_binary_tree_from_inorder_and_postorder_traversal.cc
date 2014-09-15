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
    TreeNode *build(const vector<int> &inorder, const vector<int> &postorder, int il, int ir, int pl, int pr) {
      if (pl > pr) return NULL;
      TreeNode *res = new TreeNode(postorder[pr]);
      int pos = distance(inorder.begin(), find(inorder.begin(), inorder.end(), res->val));
      int left_size = pos - il, right_size = ir - pos - 1;
      res->left = build(inorder, postorder, il, pos - 1, pl, pl + left_size - 1);
      res->right = build(inorder, postorder, pos + 1, ir, pl + left_size, pr - 1);
      return res;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
      return build(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};
