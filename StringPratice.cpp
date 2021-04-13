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
    // void rmExtraSpace(string& s) {
    //     for(int i = s.size() - 1; i > 0; i--) {
    //         if(s[i] == s[i - 1] && s[i] == ' ') {
    //             s.erase(s.begin() + i);//删除中间多余空格
    //         }
    //     }
    //     if(s.size() > 0 && s[s.size() - 1] == ' ') {//删除后面多余空格
    //         s.erase(s.begin() + s.size() - 1);
    //     }
    //     if(s.size() > 0 && s[0] == ' ') {
    //         s.erase(s.begin());
    //     }
    // }
    void rmExtraSpace(string &s) {//始终用快指针进行多余空格判断，慢指针仅用来判断存取有效数据
        int slotIndex = 0, fastIndex = 0;
        //删除前面的多余空格
        while(s.size() > 0 && s[fastIndex] == ' ' && fastIndex < s.size()) {
            fastIndex++;
        }
        //去掉中间空格
        for(; fastIndex < s.size(); fastIndex++) {
            if(fastIndex - 1 > 0 && s[fastIndex - 1] == s[fastIndex] && s[fastIndex] == ' ') {
                s[slotIndex++] = s[fastIndex];
            }
        }
        //去掉尾部多余空格
        if(fastIndex -1 > 0 && s[fastIndex - 1] == ' ') {
            s.resize(slotIndex - 1);
        }else {
            s.resize(slotIndex);
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
class KMP {
public:
    void getNext(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;//更新最长相同前后缀
        }
    }
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = -1;
        for(int i = 0;i < haystack.size(); i++) {
            while(j >= 0 && haystack[i] != needle[j + 1]) {
                j = next[j];//若不匹配，查找前缀列表
            }
            if(haystack[i] == needle[j + 1]) {
                j++;
            }
            if(j == (needle.size() - 1)){//若最长匹配长度走到了needle的末尾
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};
class GetValue{
public:
    void getValue(int *next, const string &s) {
        int j = -1;
        next[0] = j;
        for(int i = 1; i < s.size(); i++) {
            while(j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if(s[i] == s[j + 1]) {
                j++;
            }
            next[i] = j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0) {
            return 0;
        }
        int next[s.size()];
        getValue(next, s);
        int len = s.size();
        if(next[len - 1] != -1 && len % (len - (next[len - 1] + 1)) == 0){
            return true;
        }
        return false;
    }
};
 int main(void) {
     cout<<"白尼屯万岁！"<<endl;
     return 0;
 }