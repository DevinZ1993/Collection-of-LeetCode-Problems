class MyCircularQueue {
 public:
  MyCircularQueue(int k) : buffer_(k + 1) {}

  bool enQueue(int value) {
    if (isFull()) {
      return false;
    }
    buffer_[end_] = value;
    end_ = (end_ + 1) % buffer_.size();
    return true;
  }

  bool deQueue() {
    if (isEmpty()) {
      return false;
    }
    start_ = (start_ + 1) % buffer_.size();
    return true;
  }

  int Front() { return isEmpty() ? -1 : buffer_[start_]; }

  int Rear() {
    return isEmpty() ? -1
                     : buffer_[(end_ + buffer_.size() - 1) % buffer_.size()];
  }

  bool isEmpty() { return start_ == end_; }

  bool isFull() { return (end_ + 1) % buffer_.size() == start_; }

 private:
  vector<int> buffer_;
  int start_ = 0;
  int end_ = 0;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
