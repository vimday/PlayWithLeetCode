#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
  bool isMatch(string s1, string s2) {
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i%s2.size()]) return false;
    }
    return true;
  }
  string gcdOfStrings(string str1, string str2) {
    int l1 = str1.size();
    int l2 = str2.size();
    int l3 = gcd(l1, l2);
    string str3 = str1.substr(0, l3);
    if (isMatch(str1, str3) && isMatch(str2, str3)) return str3;
    return "";
  }
};