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
    TreeNode *buildTree(int low, int upp, const vector<int> &num) {
      if (low > upp) return NULL;
      int mid = (low + upp) >> 1;
      TreeNode *res = new TreeNode(num[mid]);
      res->left = buildTree(low, mid - 1, num);
      res->right = buildTree(mid + 1, upp, num);
      return res;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
      return buildTree(0, num.size() - 1, num);
    }
};
