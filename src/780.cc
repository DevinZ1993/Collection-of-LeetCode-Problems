class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    if (tx < sx || ty < sy) {
      return false;
    }
    while (tx > sx || ty > sy) {
      if (tx < ty) {
        swap(sx, sy);
        swap(tx, ty);
      }
      int delt_x = (tx - sx) / ty * ty;
      if (delt_x == 0) {
        return false;
      }
      tx -= delt_x;
    }
    return tx == sx && ty == sy;
  }
};
