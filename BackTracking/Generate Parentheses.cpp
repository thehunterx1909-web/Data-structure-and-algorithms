#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
private:
    vector<string> ans;
    void backTrack(string &s, int open, int close, int n){
        if(s.size() == n * 2){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            backTrack(s, open + 1, close, n);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            backTrack(s, open, close + 1, n);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s;
        s.reserve(n * 2);
        backTrack(s, 0, 0, n);
        return ans;
    }
};
int main(){
    
}