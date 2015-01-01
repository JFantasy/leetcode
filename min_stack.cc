class MinStack {
  public:
    void push(int x) {
      stk_.push(x);
      if (min_.empty() || min_.top() >= x) min_.push(x);
    }

    void pop() {
      if (!stk_.empty()) {
        if (stk_.top() == min_.top()) min_.pop();
        stk_.pop();
      }
    }

    int top() {
      return stk_.top();
    }

    int getMin() {
      return min_.top();
    }
  private:
    stack<int> stk_, min_;
};
