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
      for (RandomListNode *current = head; current != nullptr; current = current->next) {
        RandomListNode *node = new RandomListNode(current->label);
        node->next = current->next;
        current->next = node;
        current = node;
      }
      for (RandomListNode *current = head; current != nullptr; current = current->next->next) {
        if (current->random == nullptr) continue;
        current->next->random = current->random->next;
      }
      RandomListNode *res = NULL, **p = &res;
      for (RandomListNode *current = head; current != nullptr; current = current->next) {
        *p = current->next;
        current->next = current->next->next;
        p = &((*p)->next);
      }
      return res;
    }
};

//---------

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
      if (!head) return NULL;
      map<RandomListNode *, RandomListNode *> dict;
      queue<RandomListNode *> que;
      que.push(head);
      dict[head] = new RandomListNode(head->label);
      while (!que.empty()) {
        RandomListNode *current = que.front();
        RandomListNode *real = dict[current];
        que.pop();
        if (current->next) {
          if (dict.find(current->next) == dict.end()) {
            dict[current->next] = new RandomListNode(current->next->label);
            que.push(current->next);
          }
          real->next = dict[current->next];
        } else real->next = NULL;
        if (current->random) {
          if (dict.find(current->random) == dict.end()) {
            dict[current->random] = new RandomListNode(current->random->label);
            que.push(current->random);
          }
          real->random = dict[current->random];
        } else real->random = NULL;
      }
      return dict[head];
    }
};
