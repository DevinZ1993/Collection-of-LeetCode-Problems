/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than
 * a nested list. bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a
 * single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a
 * nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
 public:
  using Iter = vector<NestedInteger>::const_iterator;

  NestedIterator(vector<NestedInteger> &nestedList) {
    path_.emplace_back(nestedList.begin(), nestedList.end());
    fetchNext();
  }

  int next() {
    int result = path_.back().first->getInteger();
    ++path_.back().first;
    fetchNext();
    return result;
  }

  bool hasNext() { return !path_.empty(); }

 private:
  void fetchNext() {
    while (true) {
      if (path_.back().first == path_.back().second) {
        path_.pop_back();
        if (path_.empty()) {
          break;
        }
        ++path_.back().first;
        continue;
      }
      if (path_.back().first->isInteger()) {
        break;
      }
      auto &lst = path_.back().first->getList();
      path_.emplace_back(lst.begin(), lst.end());
    }
  }

  vector<pair<Iter, Iter>> path_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
