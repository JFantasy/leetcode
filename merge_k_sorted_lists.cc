/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
      ListNode *res = NULL;
      priority_queue<pair<int, int> > que;
      for (int i = 0; i < lists.size(); ++ i) {
        if (lists[i]) que.push(make_pair(-lists[i]->val, i));
      }
      while (!que.empty()) {
        int index = que.top().second;
        que.pop();
        ListNode *min_node = lists[index];
        lists[index] = lists[index]->next;
        min_node->next = res;
        res = min_node;
        if (lists[index]) que.push(make_pair(-lists[index]->val, index));
      }
      return res;
    }
};
