//#347 leetcode
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for(auto n:nums){
            mp[n]++;
        }
        priority_queue<pair<int, int>> q;
        for(auto m:mp){
            q.push({m.first, m.second});
        }
        vector<int> res;
        for(int i = 1; i <= k; i++){
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};