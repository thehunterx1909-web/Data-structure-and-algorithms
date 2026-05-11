#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int coinChange(vector<int>& coins, int amount){
    if(amount < 0) return -1;
    if(amount == 0) return 0;
    int min_coin = INT_MAX;

    for(int coin : coins){
        int res = coinChange(coins, amount - coin);
        if(res >= 0 && res < min_coin){
            min_coin = res + 1;
        }
    }
    return (min_coin == INT_MAX) ? -1 : min_coin;
}

int main(){
    int n; cin >> n;
    int amount; cin >> amount;
    vector<int> coins;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        coins.push_back(x);
    }
    cout << coinChange(coins, amount);
}