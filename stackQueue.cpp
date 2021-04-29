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
class EvalRPN {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+" || tokens[i] == "-" 
            || tokens[i] == "*" || tokens[i] == "/") {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "/") st.push(num2 / num1);
                if(tokens[i] == "*") st.push(num2 * num1);
            }else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};