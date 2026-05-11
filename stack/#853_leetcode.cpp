// car fleet - 853 leetcode
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> car;
        int n = position.size();
        for(int i = 0; i < n; i++){
          car.push_back({position[i], speed[i]});
        }
        sort(car.begin(), car.end(), greater<pair<int,int>>());
        stack<double> s;
        for(pair<int,int> x:car){
            int pos = x.first;
            int spd = x.second;
            double t = (double)(target - pos)/spd;
            if(s.empty() || t > s.top()){
                s.push(t);
            }
        }
        return s.size();
    }
};
int main(){
    
}