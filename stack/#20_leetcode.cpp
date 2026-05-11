//Valid Parentheres - Bai 20 leetcode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } else {
                if(st.empty()) return false;
                char t = st.top();
                st.pop();
                if(s[i] == ')' && t != '(') return false;
                if(s[i] == '}' && t != '{') return false;
                if(s[i] == ']' && t != '[') return false;
            }
        }
        return st.empty();
    }
};

int main(){
    
}
