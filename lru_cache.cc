class LRUCache{
  public:
    unordered_map<int, int> dict_;
    unordered_map<int, list<int>::iterator> pos_;
    list<int> current_list_;
    int capacity_;

    LRUCache(int capacity) {
      dict_.clear();
      pos_.clear();
      current_list_.clear();
      capacity_ = capacity;
    }

    int get(int key) {
      if (dict_.find(key) == dict_.end()) return -1;
      int res = dict_[key];
      update(key);
      return res;
    }

    void set(int key, int value) {
      if (dict_.find(key) == dict_.end() && dict_.size() == capacity_) pop();
      dict_[key] = value;
      update(key);
    }

  private:
    void update(const int &key) {
      if (pos_.find(key) != pos_.end()) {
        list<int>::iterator iter = pos_[key];
        current_list_.erase(iter);
      }
      current_list_.push_back(key);
      pos_[key] = -- current_list_.end();
    }

    void pop() {
      int key = *current_list_.begin();
      dict_.erase(key);
      pos_.erase(key);
      current_list_.pop_front();
    }
};
