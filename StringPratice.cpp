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
 int main(void) {
     cout<<"白尼屯万岁！"<<endl;
     return 0;
 }