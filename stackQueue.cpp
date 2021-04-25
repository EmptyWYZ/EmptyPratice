#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;
class RemoveDuplicates{
    public:
        string removeDuplicates(string S) {
        stack<int> st;
        // for(int i = 0; i < S.size(); i++) {
        //     if(st.empty() || st.top() != S[i]) {
        //         st.push(S[i]);
        //     }else{
        //         st.pop();
        //     }
        // }
        for(char s :S){
            if(st.empty() || st.top() != s) {
                st.push(s);
            }else{
                st.pop();
            }           
        }
        string ret;
        while(!st.empty()) {
            ret += st.top();
            st.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};