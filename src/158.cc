/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
 public:
  /**
   * @param buf Destination buffer
   * @param n   Number of characters to read
   * @return    The number of actual characters read
   */
  int read(char *buf, int n) {
    int cnt = 0;
    while (cnt < n && index_ < len_) {
      buf[cnt++] = buffer_[index_++];
    }
    while (cnt < n) {
      index_ = 0;
      len_ = read4(buffer_.data());
      if (len_ == 0) {
        break;
      }
      while (cnt < n && index_ < len_) {
        buf[cnt++] = buffer_[index_++];
      }
    }
    return cnt;
  }

 private:
  array<char, 4> buffer_;
  int len_ = 0;
  int index_ = 0;
};
