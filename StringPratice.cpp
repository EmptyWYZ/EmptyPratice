#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
class ReverseString {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--){
            // int tmp = s[i];
            // s[i] = s[j];
            // s[j] = tmp;
            swap(s[i], s[j]);
        }
    }
};
class ReverseStr {
public:
    string reverseStr(string s, int k) {
        int len = s.size() - 1;
        for(int i = 0; i < len;) {
            int tmp = len - i;
            if(tmp < k) {
                reverse(s.begin() + i, s.end());
            }else if(tmp < 2 * k && tmp > k) {
                reverse(s.begin() + i, s.begin() + i + k);
            }else{
                reverse(s.begin() + i, s.begin() + i + k);                
            }
            i = i + 2 * k;
        }
        return s;
    }
};
class ReplaceSpace {
public:
    string replaceSpace(string s) {
        //先扩充数组，再进行替换，双指针
        int count = 0;
        int oldSize = s.size();
        for (int i = 0; i < oldSize; i++) {
            if(s[i] == ' ') {
                count++;
            }
        }
        s.resize(s.size() + count * 2);
        int newSize = s.size();
        for(int i = newSize - 1, j = oldSize - 1; j < i; i--, j--) {
            if(s[j] != ' ') {
                s[i] = s[j];
            }else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};
class ReverseWords {
public:
    void reversestr(string& s, int start, int end) {
        for(int i = start , j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    void rmExtraSpace(string& s) {
        for(int i = s.size() - 1; i > 0; i--) {
            if(s[i] == s[i - 1] && s[i] == ' ') {
                s.erase(s.begin() + i);//删除中间多余空格
            }
        }
        if(s.size() > 0 && s[s.size() - 1] == ' ') {//删除后面多余空格
            s.erase(s.begin() + s.size() - 1);
        }
        if(s.size() > 0 && s[0] == ' ') {
            s.erase(s.begin());
        }
    }
    string reverseWords(string s) {
        //双指针法删除多余内存
        rmExtraSpace(s);
        // //反转字符串
        reverse(s.begin(), s.end());
        // reverse(s, 0, s.size() - 1);
        // //反转单词，遇到空格停下来
        int start = 0, end = 0;
        bool flag = false;
        for(int i = 0; i < s.size(); i++) {
            if((!flag) || (s[i] != ' ' && s[i - 1] == ' ')) {//开始进入单词
                start = i;
                flag = true;
            }
            if(flag && (i == (s.size() - 1)) && s[i] != ' ') {//字符串的最后位置无空格
                end = i;
                reversestr(s, start, end);
                flag = false;
            }
            if(flag && s[i] == ' ' && s[i - 1] != ' ') {//遇到空格停下来，单词结束
                end = i - 1;
                reversestr(s, start, end);
                flag = false;
            }

        }
        return s;
    }
};
 int main(void) {
     cout<<"白尼屯万岁！"<<endl;
     return 0;
 }