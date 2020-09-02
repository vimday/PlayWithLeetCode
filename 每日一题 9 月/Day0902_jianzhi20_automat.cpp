/*
 * @Author      :vimday
 * @Desc        :
 * @Url         :
 * @File Name   :Day0902_jianzhi20_automat.cpp
 * @Created Time:2020-09-02 11:21:16
 * @E-mail      :lwftx@outlook.com
 * @GitHub      :https://github.com/vimday
 */
#include <bits/stdc++.h>
using namespace std;
void debug() {
#ifdef LOCAL
    freopen("E:\\Cpp\\in.txt", "r", stdin);
    freopen("E:\\Cpp\\out.txt", "w", stdout);
#endif
}
class Solution {
public:
    bool isNumber(string s) {
        size_t i = s.find_first_not_of(' ');  //第一个不是空格的位置
        if (i == string::npos) return false;
        size_t j = s.find_last_not_of(' ');  //最后一个不是空格的位置
        s = s.substr(i, j - i + 1);          //去除首尾空格
        if (s.empty()) return false;
        size_t k = s.find_first_of('E');
        if (k != string::npos) s[k] = 'e';  //大写转小写
        size_t pos = s.find('e');
        if (pos == string::npos) return judgeLeft(s);  //没有e
        return judgeLeft(s.substr(0, pos)) && judgeRight(s.substr(pos + 1));
    }

    bool judgeLeft(string s) {
        if (s.empty()) return false;
        if (s[0] == '+' || s[0] == '-') s.erase(0, 1);
        bool flag = false;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) continue;
            //符号位只能在第一位
            if (s[i] == '.') {
                if (flag) return false;  //有多个小数点，返回false
                flag = true;             //记录已经有一个小数点
            } else
                return false;
        }
        return !s.empty() && s != ".";
    }

    bool judgeRight(string s) {
        cout << s << endl;
        if (s.empty()) return false;
        if (s[0] == '+' || s[0] == '-') s.erase(0, 1);
        //右边不能出现小数点，所以出现除符号位的非纯数字表示指数不合法
        for (int i = 0; i < s.size(); ++i) {
            if (!isdigit(s[i])) return false;
        }
        return !s.empty();
    }
};

class Solution {
public:
    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END,
    };

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_SPACE,
        CHAR_ILLEGAL,
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else if (ch == ' ') {
            return CHAR_SPACE;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        unordered_map<State, unordered_map<CharType, State>> transfer{
            {STATE_INITIAL, {
                                {CHAR_SPACE, STATE_INITIAL},
                                {CHAR_NUMBER, STATE_INTEGER},
                                {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                                {CHAR_SIGN, STATE_INT_SIGN},
                            }},
            {STATE_INT_SIGN, {
                                 {CHAR_NUMBER, STATE_INTEGER},
                                 {CHAR_POINT, STATE_POINT_WITHOUT_INT},
                             }},
            {STATE_INTEGER, {
                                {CHAR_NUMBER, STATE_INTEGER},
                                {CHAR_EXP, STATE_EXP},
                                {CHAR_POINT, STATE_POINT},
                                {CHAR_SPACE, STATE_END},
                            }},
            {STATE_POINT, {
                              {CHAR_NUMBER, STATE_FRACTION},
                              {CHAR_EXP, STATE_EXP},
                              {CHAR_SPACE, STATE_END},
                          }},
            {STATE_POINT_WITHOUT_INT, {
                                          {CHAR_NUMBER, STATE_FRACTION},
                                      }},
            {STATE_FRACTION, {
                                 {CHAR_NUMBER, STATE_FRACTION},
                                 {CHAR_EXP, STATE_EXP},
                                 {CHAR_SPACE, STATE_END},
                             }},
            {STATE_EXP, {
                            {CHAR_NUMBER, STATE_EXP_NUMBER},
                            {CHAR_SIGN, STATE_EXP_SIGN},
                        }},
            {STATE_EXP_SIGN, {
                                 {CHAR_NUMBER, STATE_EXP_NUMBER},
                             }},
            {STATE_EXP_NUMBER, {
                                   {CHAR_NUMBER, STATE_EXP_NUMBER},
                                   {CHAR_SPACE, STATE_END},
                               }},
            {STATE_END, {
                            {CHAR_SPACE, STATE_END},
                        }}};

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
    }
};