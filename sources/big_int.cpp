#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;
int charToDeci(char ch) { return ch - '0'; }
char deciToChar(int dc) { return dc + '0'; }
string addBigInt(string s1, string s2) {
  if (s1.size() > s2.size()) {
    swap(s1, s2);
  }

  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  string result = "";
  int carry = 0;
  for (int i = 0; i < s1.size(); i++) {
    int sum = charToDeci(s1[i]) + charToDeci(s2[i]) + carry;
    result.push_back(deciToChar(sum % 10));
    carry = sum / 10;
  }

  for (int i = s1.length(); i < s2.size(); i++) {
    int sum = charToDeci(s2[i]) + carry;
    result.push_back(deciToChar(sum % 10));
    carry = sum / 10;
  }
  if (carry) {
    result.push_back('1');
  }
  reverse(result.begin(), result.end());
  return result;
}
