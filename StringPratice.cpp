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
 int main(void) {
     cout<<"白尼屯万岁！"<<endl;
     return 0;
 }