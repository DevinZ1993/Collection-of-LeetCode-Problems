class Fancy {
 public:
  Fancy() {}

  void append(int val) {
    long long x, y;
    gcd(a, mod, x, y);
    nums_.push_back((val + mod - b) % mod * x % mod);
  }

  void addAll(int inc) { b = (b + inc) % mod; }

  void multAll(int m) {
    a = a * m % mod;
    b = b * m % mod;
  }

  int getIndex(int idx) {
    if (idx >= nums_.size()) {
      return -1;
    }
    return (a * nums_[idx] % mod + b) % mod;
  }

 private:
  long long gcd(long long a, long long b, long long &x, long long &y) {
    if (a == 0) {
      x = 0;
      y = 1;
      return b;
    }
    long long next_x, next_y;
    long long g = gcd(b % a, a, next_x, next_y);
    y = next_x;
    x = (next_y + mod - b / a * next_x % mod) % mod;
    return g;
  }

  static constexpr long long mod = 1'000'000'007LL;

  vector<int> nums_;
  long long a = 1;
  long long b = 0;
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
