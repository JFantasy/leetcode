/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
      while (root != nullptr) {
        stk_.push(root);
        root = root->left;
      }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
      return !stk_.empty();
    }

    /** @return the next smallest number */
    int next() {
      TreeNode *current = stk_.top();
      stk_.pop();
      int res = current->val;
      current = current->right;
      while (current != nullptr) {
        stk_.push(current);
        current = current->left;
      }
      return res;
    }
  private:
    stack<TreeNode *> stk_;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
