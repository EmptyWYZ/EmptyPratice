#include<iostream>
#include<string>
#include<vector>
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
 int main(void) {
     cout<<"白尼屯万岁！"<<endl;
     return 0;
 }