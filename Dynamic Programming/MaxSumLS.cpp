#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int solve(vector<int> a){
    vector<int> dp(a.size() + 1);
    dp[0] = a[0];
    for(int i = 1; i < a.size(); i++){
        dp[i] = max(0, dp[i - 1]) + a[i];
    }
    vector<int>::iterator max_it = max_element(dp.begin(), dp.end());
    return *max_it;
}

int main(){
    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n ;i++){
        int x; cin >> x;
        a.push_back(x);
    }
    cout << solve(a);
}