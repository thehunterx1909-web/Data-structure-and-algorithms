#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int s:stones){
            q.push(s);
        }
        while(q.size() > 1){
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(x == y){
                continue;
            }else{
                q.push(y - x);
            }
        }
        return q.empty() ? 0 : q.top();
    }
};

int main(){
    
}