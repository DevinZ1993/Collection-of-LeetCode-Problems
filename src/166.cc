class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    long long a = numerator;
    long long b = denominator;
    string result;
    if (a == 0) {
      return "0";
    } else if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
      result.push_back('-');
    }
    a = abs(a);
    b = abs(b);
    result.append(to_string(a / b));
    a %= b;
    if (a == 0) {
      return result;
    }
    result.push_back('.');
    string frac;
    map<long long, int> indices;
    int start_index = -1;
    while (a > 0) {
      if (auto it = indices.find(a); it != indices.end()) {
        start_index = it->second;
        break;
      }
      indices.emplace(a, frac.size());
      frac.push_back(static_cast<char>('0' + 10 * a / b));
      a = 10 * a % b;
    }
    if (a == 0) {
      result.append(frac);
    } else {
      result.append(frac.substr(0, start_index));
      result.push_back('(');
      result.append(frac.substr(start_index));
      result.push_back(')');
    }
    return result;
  }
};
