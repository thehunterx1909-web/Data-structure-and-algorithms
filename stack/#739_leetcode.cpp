//Daily Temperatures - bai 739 leetcode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> tmp;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            while(!tmp.empty() && temperatures[i] > temperatures[tmp.top()]){
                int idx = tmp.top();
                tmp.pop();
                ans[idx] = i - idx;
            }
            tmp.push(i);
        }
        return ans;
    }
};
int main(){
    
} 