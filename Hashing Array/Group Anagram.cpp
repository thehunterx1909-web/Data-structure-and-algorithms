//#49 leetcode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;

        for(string &s:strs){
            string key = s;
            sort(key.begin(), key.end());
            ans[key].push_back(s);
        }

        vector<vector<string>> res;
        for(auto &kq:ans){
            res.push_back(kq.second);
        }
        return res;
    }
};
int main(){
    
}