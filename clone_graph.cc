/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
  public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
      if (!node) return NULL;
      map<int, UndirectedGraphNode *> dict;
      queue<UndirectedGraphNode *> que;
      que.push(node);
      dict[node->label] = new UndirectedGraphNode(node->label);
      while (!que.empty()) {
        UndirectedGraphNode *current = que.front();
        UndirectedGraphNode *real = dict[current->label];
        que.pop();
        for (int i = 0; i < current->neighbors.size(); ++ i) {
          int label = current->neighbors[i]->label;
          if (dict.find(label) == dict.end()) {
            dict[label] = new UndirectedGraphNode(label);
            que.push(current->neighbors[i]);
          }
          real->neighbors.push_back(dict[label]);
        }
      }
      return dict[node->label];
    }
};
