class Solution {
 public:
  int maxPoints(vector<vector<int>> &points) {
    if (points.size() == 1) {
      return 1;
    }
    using Line = tuple<long long, long long, long long>;
    struct LineHasher {
      size_t operator()(const Line &line) const {
        static hash<long long> int_hash;
        return int_hash(get<0>(line)) ^ int_hash(get<1>(line)) ^
               int_hash(get<2>(line));
      }
    };
    unordered_map<Line, unordered_set<int>, LineHasher> line_map;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        long long a = 0LL + points[i][1] - points[j][1];
        long long b = 0LL + points[j][0] - points[i][0];
        long long c = 1LL * points[j][0] * points[i][1] -
                      1LL * points[i][0] * points[j][1];
        const long long g = gcd(abs(a), gcd(abs(b), abs(c)));
        a /= g;
        b /= g;
        c /= g;
        if (a < 0 || (a == 0 && b < 0)) {
          a = -a;
          b = -b;
          c = -c;
        }
        auto &point_set = line_map[Line{a, b, c}];
        point_set.insert(i);
        point_set.insert(j);
      }
    }
    int result = 0;
    for (const auto &[_, point_set] : line_map) {
      result = max<int>(result, point_set.size());
    }
    return result;
  }

 private:
  long long gcd(long long a, long long b) const {
    if (a > b) {
      return gcd(b, a);
    }
    if (a == 0) {
      return b;
    }
    return gcd(b % a, a);
  }
};
