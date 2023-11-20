class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (smallers_.empty() || num <= smallers_.top()) {
      smallers_.push(num);
      if (smallers_.size() > largers_.size() + 1) {
        largers_.push(-smallers_.top());
        smallers_.pop();
      }
    } else {
      largers_.push(-num);
      if (largers_.size() > smallers_.size()) {
        smallers_.push(-largers_.top());
        largers_.pop();
      }
    }
  }

  double findMedian() {
    if (smallers_.size() == largers_.size()) {
      return 0.5 * (smallers_.top() - largers_.top());
    }
    return smallers_.top();
  }

 private:
  priority_queue<int> smallers_;
  priority_queue<int> largers_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
